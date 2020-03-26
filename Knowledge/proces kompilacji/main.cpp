// main.cpp
//
//Preprocesor -> dyrektywy preprocesora.
//			g++ main.cpp class.cpp -E > main_class.ii
//			cpp -x c++ main.cpp > main.ii
//			cpp -x c++ class.cpp > class.ii
//Kompilator
//		Diagnostyka -> sprawdzanie składni i semantyki.
//		Optymalizaja -> otymalizacja kodu.
//		Generowanie kodu assemblera -> przełożenie kodu na assemblera.
//			g++ main.cpp class.cpp -S
//			cc -x c++ main.ii -S
//			cc -x c++ class.ii -S
//Assembler -> assembluje kod do kodu maszynowego, tworzy pliki 
//				obiektowe, są one zbliżone budową do plików 
//				wykonywalnych - z tą różnicą, że pliki obiektowe nie 
//				posiadają referencji do wykorzystywanych symboli.
//			g++ main.cpp class.cpp -c
//			as main.s -o main.o
//			as class.s -o class.o
//Do tego momentu każdy plik cpp jest przetwarzany osobno, teraz będą 
//połączone.
//Konsolidator -> łączenie plików, odnajdywanie referencji i dokonywana jest 
//				dodatkowa optymalizacja, która wcześniej nie mogła być
//				przeprowadzona ze wzglądu na brak wszystkich danych, teraz
//				musi się znaleźć funkcja main, biblioteki statyczne są 
//				dołanczane w tym momencie, a biblioteki dynamiczne w momęcie
//				wykonywania programu.
//			g++ main.cpp class.cpp
//			do wygenerowania tego za pomocą ld trzeba podłączać wszystkie 
//			biblioteki, najlepiej to zrobić wywołując: g++ -v main.cpp 
//			class.cpp i przekopiować biblioteki z sekcji COLLECT_GCC_OPTIONS=, 
//			w moim przypadku to wyglądało tak:
//			ld main.o class.o -plugin /usr/lib/gcc/x86_64-linux-gnu/9/liblto_plugin.so -plugin-opt=/usr/lib/gcc/x86_64-linux-gnu/9/lto-wrapper -plugin-opt=-fresolution=/tmp/cck8GR3J.res -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc --build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie -z now -z relro /usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o /usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/9/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/9 -L/usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/9/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/9/../../..  -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-linux-gnu/9/crtendS.o /usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/crtn.o
//

#include <iostream>
#include "class.h"

#define NUMBER 34

using namespace std;

int main()
{
    cout << "Hello World!\n";
    Class C;
    cout << C.Method1(NUMBER) << endl;
    cout << C.Method2(NUMBER) << endl;
}

