// unique_ptr.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//czemu make_unique:
//krotszy zapis () dwa razy nie ttrzeba pisać, jeśli stosujemy auto, 
//można utowożyc zasadę nie używa się new i delete i 
//Nie jest zdefiniowana kolejność ewaluacji argumentów finkcji, jeśli argument zawiedzie to nie ma kto posprzątać po new.
//foo(unique_ptr<X>(new X), unique_ptr<Y>(new Y))

//Resource Acquisition Is Initialization (RAII) -
//zdobywanie zasobów jest inicjowaniem.

#include <iostream>
#include <memory>
#include <functional>
//C++11 
//unique_ptr

using namespace std;
class MyClass
{
public:
    MyClass()
    {
        cout << "konstruktor" << endl;
    }

    ~MyClass()
    {
        cout << "desktruktor" << endl;
    }
};

/*void foo(unique_ptr<int> a, unique_ptr<int> b)
{
    ;
}*/

int main()
{
    //foo(make_unique<int>(), make_unique<int>());
    /*unique_ptr<int> ptr(new int);
    *ptr = 4;
    cout << *ptr << endl;
    
    //RAII
    unique_ptr<int> ptr2 = move(ptr);
    cout << *ptr2 << endl;*/


    //unique_ptr<MyClass> ptr2(new MyClass);

    //unique_ptr<int[]> ptr2(new int[10]);
    //unique_ptr<int[]> ptr2 = make_unique<int[]>(10);
    //ptr2[2] = 3;
    //cout << ptr2[2] << " " << ptr2[1] << endl;

    //C++14
    //make_unique()

    //auto ptr2 = make_unique<int>();
    //*ptr2 = 3;
    //cout << *ptr2 << endl;

    /*unique_ptr<MyClass, function<void(MyClass*)>> ptr2(new MyClass, [](MyClass* ptr) {
        cout << "Moj destruktor" << endl;
        delete ptr;
        });*/

    return 0;
}
