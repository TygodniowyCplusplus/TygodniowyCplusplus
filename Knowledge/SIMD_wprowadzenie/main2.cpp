#include <iostream>

int main()
{
	double a[16] = {1}; 
	double b[16] = {2};
	double c[16] = {0};
	const int count = 16;
	#pragma omp simd
	for (int i = 0; i < count; i++)
	{
		c[i] = a[i]+b[i];
	}

	return c[0];
}
