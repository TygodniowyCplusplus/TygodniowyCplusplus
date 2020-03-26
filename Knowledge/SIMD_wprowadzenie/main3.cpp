#include <iostream>
#include <immintrin.h>
#include <algorithm>

int main()
{
	alignas(32) float a[32];
	alignas(32) float b[32];
	alignas(32) float c[32];
	alignas(32) float d[32];
	std::fill(a, std::end(a), 1);
	std::fill(b, std::end(b), 2);
	std::fill(c, std::end(c), 3);
	std::fill(d, std::end(d), 0);
	//for(int i = 0; i < 32; ++i)
	//{
	// d[i] = (a[i]*b[i] + c[i]) + (a[i]*b[i]);
	//}
	//__restrict__ mówi, że tylko ten wskaźnik ma dostęp do pamięci
	//na którą wskazuje.
	__m256* __restrict__  vecA = (__m256*) & a[0];
	__m256* __restrict__  vecB = (__m256*) & b[0];
	__m256* __restrict__  vecC = (__m256*) & c[0];
	__m256* __restrict__  vecD = (__m256*) & d[0];
	for (int i = 0; i < 4; ++i)
	{
		__m256 tmp1 = _mm256_mul_ps(vecA[i], vecB[i]);
		__m256 tmp2 = _mm256_add_ps(tmp1, vecC[i]);
		vecD[i] = _mm256_add_ps(tmp1, tmp2);
	}

	std::cout << "Result: ";
	for (int i = 0; i < 32; ++i)
	{
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
