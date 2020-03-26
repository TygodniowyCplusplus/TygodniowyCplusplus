// shared_ptr.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <memory>
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

int main()
{
    std::cout << "Hello World!\n";

    auto ptr6 = make_shared<MyClass>();
    cout << ptr6.get() << endl;
    cout << ptr6.use_count() << endl;
    auto ptr7 = ptr6;
    cout << ptr6.get() << endl;
    cout << ptr6.use_count() << endl;
    ptr6.reset(new MyClass);
    cout << ptr6.get() << endl;
    cout << ptr6.use_count() << endl;
    //ptr6.reset();
    auto ptr8 = ptr6;
    cout << ptr6.get() << endl;
    cout << ptr6.use_count() << endl;
    ptr6 = make_shared<MyClass>();
    cout << ptr8.get() << endl;
    cout << ptr8.use_count() << endl;
    cout << ptr6.get() << endl;
    cout << ptr6.use_count() << endl;
    std::cout << "Hello World!\n";
    /*shared_ptr<int> ptr(new int);
    shared_ptr<int> ptr2 = make_shared<int>();

    auto ptr3 = ptr2;
    *ptr2 = 8;
    cout << *ptr3 << endl;
    cout << ptr3 << endl;
    cout << ptr3.get() << endl;
    cout << ptr3.use_count() << endl;
    //int* p = ptr3.get();
    //cout << *p << endl;
    //cout << p << endl;
    cout << ptr3.use_count() << endl;*/

    /*shared_ptr<int[]> ptr4(new int[10]);
    //od C++20  można: make_shared<int[]>(10);
    //shared_ptr<int[]> ptr5 = make_shared<int[]>(10);
    ptr4[5] = 9;
    cout << ptr4[5] << endl;*/

    //shared_ptr<int> ptr3(new int, [] (int * tmp){cout << "specjalny destructor"; });
}
