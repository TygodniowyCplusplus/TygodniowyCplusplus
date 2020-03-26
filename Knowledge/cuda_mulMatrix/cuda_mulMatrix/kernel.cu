
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>

//Mno¿enie macierzy
// 1 2 * 5 6 = (1*5+2*7) (1*6+2*8)
// 3 4   7 8   (3*5+4*7) (3*6+4*8)

__global__ void matrixMul(int* m, int* n, int* p, int size)
{	
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int column = blockIdx.x * blockDim.x + threadIdx.x;
	int p_sum = 0;

	for (int i = 0; i < size; ++i)
	{
		p_sum += m[row * size + i] * n[i * size + column];
	}

	p[row * size + column] = p_sum;
}

void matrixMul_seq(int* m, int* n, int* p, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			for (int k = 0; k < size; ++k)
			{
				 p[i * size + j] += m[i * size + k] * n[k * size + j];
			}
		}
	}
}

int main()
{
	//W C/C++ jest Row-major//////
	/*int tab[2][2] = {{1,2},{3,4}};
	int* tab_ptr = &tab[0][0];
	for (int i = 0; i < 4; ++i)
	{
		std::cout << *tab_ptr << " ";
		++tab_ptr;
	}
	std::cout << std::endl;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cout << tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;*/
	//////////////////////////////
	
	int n = 1 << 10; // == 1024 or 2^10
	printf("Square matrix of size %d\n", n);

	//n*m = p
	//Host Matrix  m, n, p
	int* h_m;
	int* h_n;
	int* h_p;
	int* h_p_seq;

	//Device Matrix  m, n, p
	int* d_m;
	int* d_n;
	int* d_p;

	size_t bytes = n * n * sizeof(int);

	//Allocate memory on host side
	h_m = (int*)malloc(bytes);
	h_n = (int*)malloc(bytes);
	h_p = (int*)malloc(bytes);
	h_p_seq = (int*)malloc(bytes);
	
	//Initialize matrix m, n, p
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			h_m[i * n + j] = rand() % 1024;
			h_n[i * n + j] = rand() % 1024;
			h_p_seq[i * n + j] = 0;
		}
	}

	//Allocate memoru on device side
	cudaMalloc(&d_m, bytes);
	cudaMalloc(&d_n, bytes);
	cudaMalloc(&d_p, bytes);

	//Copy data to the device
	cudaMemcpy(d_m, h_m, bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(d_n, h_n, bytes, cudaMemcpyHostToDevice);

	int threads_per_block = 16;
	dim3 block_size(threads_per_block, threads_per_block);
	dim3 grid_size(n / block_size.x, n / block_size.y);
	
	printf("Grid size X: %d, Grid size Y: %d\n", grid_size.x, grid_size.y);
	printf("block_size X: %d, block_size Y: %d\n", block_size.x, block_size.y);

	// Benchmark phase
	auto start = std::chrono::steady_clock::now();
	//Start code testing
	matrixMul<<<grid_size, block_size>>> (d_m, d_n, d_p, n);
	cudaDeviceSynchronize();
	//End code testing
	auto end = std::chrono::steady_clock::now();
	auto usecs = std::chrono::duration_cast<std::chrono::duration<float,
		std::chrono::milliseconds::period>>(end - start);
	std::cout << "Elapsed time: " << usecs.count() << " ms." << std::endl;

	// Benchmark phase
	start = std::chrono::steady_clock::now();
	//Start code testing
	matrixMul_seq(h_m, h_n, h_p_seq, n);
	//End code testing
	end = std::chrono::steady_clock::now();
	usecs = std::chrono::duration_cast<std::chrono::duration<float,
		std::chrono::milliseconds::period>>(end - start);
	std::cout << "Elapsed time: " << usecs.count() << " ms." << std::endl;

	cudaMemcpy(h_p, d_p, bytes, cudaMemcpyDeviceToHost);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(h_p[n * i + j] != h_p_seq[n * i + j])
			{
				printf("ERROR!\n");
				printf("h_p: %d, h_p_seq: %d\n", h_p[n * i + j], h_p_seq[n * i + j]);
			}
		}
	}

	free(h_m);
	free(h_n);
	free(h_p);
	free(h_p_seq);

	cudaFree(d_m);
	cudaFree(d_n);
	cudaFree(d_p);

	return 0;
}

