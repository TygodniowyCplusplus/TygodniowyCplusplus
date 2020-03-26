// SIMDI_mulMatrix.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <chrono>

const int Size = 160; //Musi być podzielne prze 4
//przy 180 już przepełnia mi się stos, więc trzeba 
//by przerobić te tablice do alokacji dynamicznej
//i tym samym przenieść te dane na stertę
const int SizeOfTabs = Size * Size;
const int Div = Size/4;

//Mnożenie macierzy m*n = p
// 1 2 * 5 6 = (1*5+2*7) (1*6+2*8)
// 3 4   7 8   (3*5+4*7) (3*6+4*8)

void matrixMul_oldWay(float* m, float* n, float* p)
{
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			for (int k = 0; k < Size; ++k)
			{
				p[i * Size + j] += m[i * Size + k] * n[k * Size + j];
			}
		}
	}
}

//Mnożenie macierzy m*n = p
// 1 2 * 5 6 = (1*5+2*7) (1*6+2*8)
// 3 4   7 8   (3*5+4*7) (3*6+4*8)
void matrixMul_newWay(float* m, float* n, float* p)
{
	float* resultRowPointer = &p[0];

	__m128 tabOfRight[Size][Div];
	for (int i = 0; i < Size; ++i)
	{
		for(int l = 0; l < Div; ++l)
			tabOfRight[i][l] = _mm_load_ps(&n[(i * Size) + (l*4)]); //5 6
	}																//7 8


	__m128 tabOfLeft[Size][Div];
	int j = 0;
	for (int i = 0; i < Size; ++i, j += Size, resultRowPointer += Size) {
		for (int k = 0; k < Size; ++k)
		{
			for (int l = 0; l < Div; ++l)
				tabOfLeft[k][l] = _mm_set1_ps(m[(k + j)]);	//1									//3
		}													//2									//4

		__m128 tabOfTmp[Size][Div];
		for (int k = 0; k < Size; ++k)
		{
			for (int l = 0; l < Div; ++l)
				tabOfTmp[k][l] = _mm_mul_ps(tabOfLeft[k][l], tabOfRight[k][l]);
		}													//5*1 6*1							//5*3 6*3
															//7*2 8*2							//7*4 8*4

		__m128 R[Div];
		for (int l = 0; l < Div; ++l) 
			R[l] = _mm_set1_ps(0);
		for (int k = 0; k < Size; ++k)
		{
			for (int l = 0; l < Div; ++l)
				R[l] = _mm_add_ps(R[l], tabOfTmp[k][l]);	//+=5*1 +=6*1						//+=5*3 +=6*3
		}													//+=2*7 +=8*2						//+=7*4 +=8*4
		for (int l = 0; l < Div; ++l)
			_mm_store_ps(resultRowPointer + (l*4), R[l]);	//29 22								//29 50

	}
}

int main()
{
	alignas(32) float mOld[SizeOfTabs];
	alignas(32) float nOld[SizeOfTabs];
	alignas(32) float pOld[SizeOfTabs];
	
	std::fill(pOld, std::end(pOld), 0);

	//Inicjalizujemy
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			mOld[i * Size + j] = rand() % 10;
			nOld[i * Size + j] = rand() % 10;
		}
	}
	
	std::cout << "oldWay"<< std::endl;
	// Benchmark phase
	auto start = std::chrono::steady_clock::now();
	//Start code testing
	matrixMul_oldWay(mOld, nOld, pOld);
	//End code testing
	auto end = std::chrono::steady_clock::now();
	auto usecs = std::chrono::duration_cast<std::chrono::duration<float,
		std::chrono::milliseconds::period>>(end - start);
	std::cout << "Elapsed time: " << usecs.count() << " ms." << std::endl;
	

	alignas(32) float mNew[SizeOfTabs];
	alignas(32) float nNew[SizeOfTabs];
	alignas(32) float pNew[SizeOfTabs];

	std::fill(pNew, std::end(pNew), 0);

	//Inicjalizujemy
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			mNew[i * Size + j] = mOld[i * Size + j];
			nNew[i * Size + j] = nOld[i * Size + j];
		}
	}

	std::cout << "newWay" << std::endl;
	// Benchmark phase
	start = std::chrono::steady_clock::now();
	//Start code testing
	matrixMul_newWay(mNew, nNew, pNew);
	//End code testing
	end = std::chrono::steady_clock::now();
	usecs = std::chrono::duration_cast<std::chrono::duration<float,
		std::chrono::milliseconds::period>>(end - start);
	std::cout << "Elapsed time: " << usecs.count() << " ms." << std::endl;

	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			if (pNew[Size * i + j] != pOld[Size * i + j])
			{
				printf("ERROR!\n");
				printf("pNew: %f, pOld: %f\n", pNew[Size * i + j], pOld[Size * i + j]);
			}
		}
	}

	return 0;
}
