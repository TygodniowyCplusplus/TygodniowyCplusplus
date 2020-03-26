// weak_ptr.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <memory>

using namespace std;

//Wskaźnik typu std::weak_ptr obserwuje wskazywany obiekt, 
//ale nie ma kontroli nad czasem jego życia i 
//nie może zmieniać jego licznika odniesień.

struct Cyclic
{
    shared_ptr<Cyclic> me_;
    /* … */
};

void foo()
{
    shared_ptr<Cyclic> cptr = make_shared<Cyclic>();
    cptr->me_ = cptr;
}  // wyciek pamięci

class MyClass
{
public:
    MyClass()
    {
        //cout << "konstruktor" << endl;
    }

    ~MyClass()
    {
        //cout << "desktruktor" << endl;
    }
    void do_stuff()
    {
        cout << "do stuff" << endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    weak_ptr<MyClass> weakPtr;

    shared_ptr<MyClass> ShPtr = make_shared<MyClass>();
    weakPtr = ShPtr;
    cout << ShPtr << " " << ShPtr.use_count() << endl;

    shared_ptr<MyClass> ShPtr2 = weakPtr.lock();
    cout << ShPtr2 << " " << ShPtr2.use_count() << endl;

    if (ShPtr2)
    {
        ShPtr2->do_stuff();
    }

    cout << weakPtr.use_count() << endl;
    /*if (weakPtr.expired())
        cout << "obiekt zostal usuniety" << endl;
    cout << "po jednym if-ie" << endl;
    ShPtr2.reset();
    ShPtr.reset();
    if (weakPtr.expired())
        cout << "obiekt zostal usuniety" << endl;*/

    cout << "wielkości:" << endl;
    cout << sizeof(weakPtr) << endl;
    cout << sizeof(ShPtr) << endl;

    unique_ptr<MyClass> uniquePtr;
    cout << sizeof(uniquePtr) << endl;

    MyClass* p;
    cout << sizeof(p) << endl;
}