// SIMD_1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include <immintrin.h> //zapewnia dostęp do
//funkcji wewnętrznych (Intrinsics)

//Funkcje wbudowane lub funkcje wewnętrzne są to
//funkcje wbudowane w kompilator. Funkcje te często
//umożliwiają stosowanie konstrukcji nieobsługiwanych
//przez język.

//Instrukcje SIMD są instrukcjami wbudowanymi.

//Instrukcja SIMD -> Single Instruction, Multiple Data
//Są to instrukcje, które przetwarzają wiele danych na podstawie
//pojedynczego rozkazu. Inaczej mówiąc można, wykonywać obliczenia
//na wielu obiektach jednocześnie, co może znacznie przyśpieszyć
//program.
//Zestawy instrukcji wykonywanych przez procesor, które
//zawierają SIMD to: SSE(Streaming SIMD Extensions),SSE2,...,
//AVX(Advanced Vector Extensions), NEON, AVX512.
//Te zestawy są implementowane w większości używanych dzisiaj
//procesorach (np. Intel, AMD, ARM, ...).


//**************************************Automatyczna wektoryzacja:

//Obliczenia na jednym obiekcie to obliczenia skalarne,
//obliczenia na większej ilości obiektów jednocześnie to obliczenia
//wektorowe.
//Procesory obsługujące SIMD posiadają przynajmniej jedną jednostkę
//wektorową VPU i zbiór rejestrów dedykowanych to obliczeń
//wektorowych. Rozmiary tych rejestrów i ich ilość zwiększa
//się z czasem.
//Linux: lscpu - można zobaczyć jakie architektury wspiera
//komputer.
//Automatyczna wektoryzacja obliczeń - kompilator automatycznie
//znajduje miejsce w programie (najczęściej pętle), które można
//zwektoryzować i robi to.
//GNU - aby włączyć automatyczną wektoryzację, należy kompilować
//z opcją -O3(to nie jest opcja domyślna) lub -ftree-vectorize.
//Aby wyłączyć auto. wektoryzację -fno-tree-vectorize.
//Aby uzyskać proces automatycznej wektoryzacji jak najbardziej
//dopasowany do danej architektury trzeba dodać flagi dedykowane
//do konkretnej architektury np. -mavx, -msse, -mavx512cd.
//Kompilatory umożliwiają generowanie raportów z automatycznej
//wektoryzacji. GNU: -fopt-info-vec-all.
//Można sprawdzić, czy wektoryzacja miała miejsce np.:
//objdump -d plik_wykonywalny > out.asm
//i sprawdzić, czy są instrukcje asemblerowe mówiące o
//wektoryzacji.
//Piszemy:
double a[16] = {1}; 
double b[16] = {2};
double c[16] = {0};
const int count = 16;
for (int i = 0; i < count; i++)
{
	c[i] = a[i]+b[i];
}
//kompilujemy to z np. flagą -mavx (256-bitowe rejestry),
//to zostanie to przekształcone na:
for (int i = 0; i < count; i += 4)
{
	c[i+0] = a[i+0]+b[i+0];
	c[i+1] = a[i+1]+b[i+1];
	c[i+2] = a[i+2]+b[i+2];
	c[i+3] = a[i+3]+b[i+3];
}
//i po kompilacji zamieni cztery instrukcje sklarne na jedną
//wektorową: vaddpd ymm, ymm, ymm


//******************************Półautomatyczna wektoryzacja:

//Dajemy kompilatorowi "podpowiedzi" gdzie ma wektoryzować i
//budujemy tak kod, aby mu to ułatwić. W C/C++ do tych podpowiedzi
//służą dyrektywy OpenMP.
//W GNU należy dodać flagę openMP: -fopenmp, optymalizacji: -O3 i 
//flage architektury np. -mavx
//#pragma omp simd - ta dyrektywa zleca zwektoryzowania danej
//pętli
//W naszym przykladzie dodjemy ją w taki sposób:
double a[16] = {1}; 
double b[16] = {2};
double c[16] = {0};
const int count = 16;
#pragma omp simd //akurat w tym przykladzie to nic nie zmieni
for (int i = 0; i < count; i++)
{
	c[i] = a[i]+b[i];
}
//Można dodawać bardziej szczegółowe dyrektywy, pomagające w lepszej 
//wektoryzacji.
//Dygresja:
	//aligned - określa listę zmiennych, których adresy dla pierwszej
	//iteracji pętli są dopasowane w pamięci do wskazanej granicy.
	//Dla różnych architektur powinny być inne dopasowania:
	//dla SSE dane powinny być dopasowane do 16 bajtów
	//dla AVX dane powinny być dopasowane do 32 bajtów
	//dla AVX-512 dane powinny być dopasowane do 64 bajtów
	//np. #pragma omp simd aligend(a,b,c:64)
	/*double a[n] __attribute__((aligend(64)));
	double b[n] __attribute__((aligend(64)));
	double c[n] __attribute__((aligend(64)));
	int count = 16;
	#pragma omp simd aligend(a,b,c:64)
	for (int i = 0; i < count; i++)
	{
	c[i] = a[i]+b[i];
	}*/
	//safelen(N) - Programista zapewnia kompilator, że nie ma
	//zależności pomiędzy N kolejno występujących po sobie
	//iteracjami pętli
	//Dyrektywy można łączyć:
	//#pragma omp simd aligend(a,b,c:64) safelen(16)
	//Wykaz dyrektyw OpenMP w przyjemnej formie:
	//https://www.openmp.org/wp-content/uploads/OpenMPRef-5.0-111802-web.pdf


//******************************Manualna wektoryzacja obliczeń:

//Można to przeprowadzić za pomocą właśnie funkcji wbudowanych.
//Za pomocą instrukcji asemblerowych lub w C/C++ za pomocą
//instrukcji intrinsic.
//Dokumentacja instrukcji intrinsic:
//https://software.intel.com/sites/landingpage/IntrinsicsGuide

//Przykładowo, dodawanie dwóch wektorów dla danych typu float:
//Architektura:SSE
#include <xmmintrin.h>
__m128 _mm_add_ps (__m128 a, __m128 b)
//Instrukcje assemblerowe: addps xmm, xmm
//Architektura:AVX
#include <immintrin.h>
__m256 _mm256_add_ps (__m256 a, __m256 b)
//Instrukcje assemblerowe: vaddps ymm, ymm, ymm
//Architektura:AVX512
#include <immintrin.h>
__m512 _mm512_add_ps (__m512 a, __m512 b)
//Instrukcje assemblerowe: vaddps zmm, zmm, zmm

//dodawanie dwóch wektorów dla danych typu double:
//Architektura:SSE2
#include <emmintrin.h>
__m128 _mm_add_pd (__m128 a, __m128 b)
//Instrukcje assemblerowe: addpd xmm, xmm
//Architektura:AVX
#include <immintrin.h>
__m256 _mm256_add_pd (__m256 a, __m256 b)
//Instrukcje assemblerowe: vaddpd ymm, ymm, ymm
//Architektura:AVX512
#include <immintrin.h>
__m512 _mm512_add_pd (__m512 a, __m512 b)
//Instrukcje assemblerowe: vaddpd zmm, zmm, zmm

//Przedrostki:
//ps (packed single) – działanie na wektorach,
//ss (scalar single) – działanie na skalarach.
//pd (packed double) – działanie na wektorach zmiennych podwójnej
//precyzji,

//Przykład:
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
__m256 * vecA = (__m256*)&a[0];
__m256 * vecB = (__m256*)&b[0];
__m256 * vecC = (__m256*)&c[0];
__m256 * vecD = (__m256*)&d[0];
for(int i = 0; i < 4; ++i)
{
	__m256 tmp1 = _mm256_mul_ps(vecA[i],vecB[i]);
	__m256 tmp2 = _mm256_add_ps(tmp1,vecC[i]);
	vecD[i] = _mm256_add_ps(tmp1,tmp2);
}
//Flagi do kompilacji na GNU: -mavx

//Nie wszystkie pętle można zwektorować np.:
for(int i = 1; i<16; ++i)
{
	C[i] = A[i] * B[i] + C[i-1];
}
//Wykonanie iteracji zależy do wcześniejszej iteracji.
//Takiej pętli nie można zwektorować.

































class Mat4
{
public:
    union
    {
        struct
        {
            float Row0[4];
            float Row1[4];
            float Row2[4];
            float Row3[4];
        } Row;
        float tab[16];
    } Data;

    Mat4() 
    { 
        for (int i = 0; i < 16; ++i)
        {
            Data.tab[i] = 3.0f;
        }
    }
};

void dotFourByFourMatrix(Mat4* left, Mat4* right, Mat4* result) {
    const __m128 BCx = _mm_load_ps((float*)&right->Data.Row.Row0[0]);
    const __m128 BCy = _mm_load_ps((float*)&right->Data.Row.Row1[0]);
    const __m128 BCz = _mm_load_ps((float*)&right->Data.Row.Row2[0]);
    const __m128 BCw = _mm_load_ps((float*)&right->Data.Row.Row3[0]);

    float* leftRowPointer = &left->Data.Row.Row0[0];
    float* resultRowPointer = &result->Data.Row.Row0[0];

    for (unsigned int i = 0; i < 4; ++i, leftRowPointer += 4, resultRowPointer += 4) {
        __m128 ARx = _mm_set1_ps(leftRowPointer[0]);
        __m128 ARy = _mm_set1_ps(leftRowPointer[1]);
        __m128 ARz = _mm_set1_ps(leftRowPointer[2]);
        __m128 ARw = _mm_set1_ps(leftRowPointer[3]);

        __m128 X = _mm_mul_ps(ARx, BCx);
        __m128 Y = _mm_mul_ps(ARy, BCy);
        __m128 Z = _mm_mul_ps(ARz, BCz);
        __m128 W = _mm_mul_ps(ARw, BCw);

        __m128 R = _mm_add_ps(X, _mm_add_ps(Y, _mm_add_ps(Z, W)));
        _mm_store_ps(resultRowPointer, R);
    }
}

int main()
{
    /*std::cout << "New way: \n";
    //Create two 256-bit argument (8 flats)
    //"ps" stands for packed single precision (aka floats)
    //256-bitowe rejestry wprowadzono od AVX
    __m256 evens = _mm256_set_ps( 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0 );
    __m256 odds = _mm256_set_ps( 1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0 );

    __m256 result = _mm256_sub_ps(evens, odds);

    float* f = (float *)&result;

    std::cout << "Result: ";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << f[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Old way: \n";
    float evens1[] = { 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0 };
    float odds1[] = { 1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0 };

    float result1[8] = { 0 };

    for (int i = 0; i < 8; ++i)
    {
        result1[i] = evens1[i] - odds1[i];
    }

    std::cout << "Result: ";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << result1[i] << " ";
    }
    std::cout << std::endl;*/

    Mat4 mat1, mat2, mat3;
    dotFourByFourMatrix(&mat1, &mat2, &mat3);
    
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << mat3.Data.tab[i * 4 + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
