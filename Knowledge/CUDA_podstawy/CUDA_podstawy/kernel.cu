#include <iostream>
#include <math.h>
#include <chrono>

// CUDA runtime
#include <cuda_runtime.h>
#include "device_launch_parameters.h"

//
//Host -> CPU
//magistrala
//Device -> GPU
//Grid:
//Block1 Block2 Block3 ... BlockN
//
//Block1:
//Thread1 Thread2 Thread3  ... ThreadN

// Kernel function to add the elements of two arrays
//__global__ wskazuje ¿e ta funkcja jest wywo³ywana na 
//GPU(device), i mo¿e byæ wywo³ywana przez kod z CPU(host)
__global__ void add1(int n, float* x, float* y)
{
    //0 1 2 '3' 4 5
    // blockDim.x =3 
    //1
    //0
	
	//blockDim.x = iloœæ w¹tków w ramach jednego bloku
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    if (idx < n) { y[idx] = x[idx] + y[idx]; }
}

__global__ void add2(int n, float* x, float* y)
{
    for (int i = 0; i < n; ++i)
        y[i] = x[i] + y[i];
}

//Old method
void addOldMethod(int n, float* x, float* y)
{
    for (int i = 0; i < n; ++i)
        y[i] = x[i] + y[i];
}

int main(void)
{
    const int N = 1000000;

    float* x, * y;

    std::cout << "New method1:" << std::endl;

    // Allocate Unified Memory – accessible from CPU or GPU
    //Alokuje pamiec w Unified Memory, i zwraca do niej 
    //wskznik, do tej pamieci maja dostêp GPU i CPU
    cudaMallocManaged(&x, N * sizeof(float));
    cudaMallocManaged(&y, N * sizeof(float));

    // initialize x and y arrays on the host
    for (int i = 0; i < N; ++i) {
        x[i] = 1.0f;
        y[i] = 2.0f;
    }
    //to jest takie wolne poniewa¿ tablice inicjalizuje CPU a 
    //korzysta z niej GPU i dlatego musi przenieœæ dane do GPU i potem 
    //z powrotem do CPU

    int blockSize;      // The launch configurator returned block size 
    int minGridSize;    // The minimum grid size needed to achieve the maximum occupancy for a full device launch 
    int gridSize;       // The actual grid size needed, based on input size 
    cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, add1, 0, N);
    // Round up according to array size 
    gridSize = (N + blockSize - 1) / blockSize;
    //977 1024

    std::cout << "How many blocks: " << gridSize << std::endl;
    std::cout << "How many threads: " << blockSize << std::endl;

    // Benchmark phase
    auto start = std::chrono::steady_clock::now();
    //Start code testing

    // Run add on the GPU
    //potrójne ostre nawiasy oznaczaj¹ ¿e kod CPU(host) wywo³uje
    //kod GPU(device)
    //pierwszy parametr oznacza ile kopi funkcji "add" ma byæ
    //wywo³ane, to znaczy ile bloków ma stworzyæ, a drugi parametr
    //ile w¹tków ma dzia³aæ w ramch tego bloku
    add1 << <gridSize, blockSize >> > (N, x, y);
    // Wait for GPU to finish before accessing on host
    cudaDeviceSynchronize();

    //End code testing
    auto end = std::chrono::steady_clock::now();
    auto usecs = std::chrono::duration_cast<std::chrono::duration<float,
        std::chrono::microseconds::period>>(end - start);
    std::cout << "Elapsed time: " << usecs.count() << " us." << std::endl;

    // Check for errors (all values should be 3.0f)
    float maxError = 0.0f;
    for (int i = 0; i < N; i++)
        maxError = fmax(maxError, fabs(y[i] - 3.0f));
    std::cout << "Max error: " << maxError << std::endl << std::endl;

    // Free memory
    cudaFree(x);
    cudaFree(y);

    std::cout << "New method2:" << std::endl;

    // Allocate Unified Memory – accessible from CPU or GPU
    cudaMallocManaged(&x, N * sizeof(float));
    cudaMallocManaged(&y, N * sizeof(float));

    // initialize x and y arrays on the host
    for (int i = 0; i < N; i++) {
        x[i] = 1.0f;
        y[i] = 2.0f;
    }

    // Benchmark phase
    start = std::chrono::steady_clock::now();
    //Start code testing


    add2 << <1, 1 >> > (N, x, y);

    cudaDeviceSynchronize();

    //End code testing
    end = std::chrono::steady_clock::now();
    usecs = std::chrono::duration_cast<std::chrono::duration<float,
        std::chrono::microseconds::period>>(end - start);
    std::cout << "Elapsed time: " << usecs.count() << " us." << std::endl;

    // Check for errors (all values should be 3.0f)
    maxError = 0.0f;
    for (int i = 0; i < N; i++)
        maxError = fmax(maxError, fabs(y[i] - 3.0f));
    std::cout << "Max error: " << maxError << std::endl << std::endl;

    // Free memory
    cudaFree(x);
    cudaFree(y);

    //Old method
    std::cout << "Old method:" << std::endl;
    x = new float[N];
    y = new float[N];

    // initialize x and y arrays on the host
    for (int i = 0; i < N; i++) {
        x[i] = 1.0f;
        y[i] = 2.0f;
    }

    // Benchmark phase
    start = std::chrono::steady_clock::now();
    //Start code testing

    // Run add on the CPU
    addOldMethod(N, x, y);

    //End code testing
    end = std::chrono::steady_clock::now();
    usecs = std::chrono::duration_cast<std::chrono::duration<float,
        std::chrono::microseconds::period>>(end - start);
    std::cout << "Elapsed time: " << usecs.count() << " us." << std::endl;

    // Check for errors (all values should be 3.0f)
    maxError = 0.0f;
    for (int i = 0; i < N; i++)
        maxError = fmax(maxError, fabs(y[i] - 3.0f));
    std::cout << "Max error: " << maxError << std::endl;

    //Free memory
    delete[] x;
    delete[] y;

    //int k;
    //std::cin >> k;
    return 0;
}

/*// Check for errors (all values should be 3.0f)
    float maxError = 0.0f;
    int howMany = 0;
    int OnElemen = 0;
    for (int i = 0; i < N; i++)
    {
        maxError = fmax(maxError, fabs(y[i] - 3.0f));
        if ((y[i] - 3.0f) != 0)
        {
            howMany += 1;
            OnElemen = i;
        }
    }
    std::cout << "Max error: " << maxError << std::endl;
    std::cout << "How many: " << maxError << std::endl;
    std::cout << "On element: " << OnElemen << std::endl;*/