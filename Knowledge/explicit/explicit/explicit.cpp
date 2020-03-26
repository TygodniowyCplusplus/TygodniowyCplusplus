// explicit.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
using namespace std;

//explicit może być zastosowane także do 
//operatorów przekształcenia, od C++11

class MyClass
{
    int iValue;
public:
    explicit MyClass(int ivalue) : iValue(ivalue) { ; }
    explicit operator bool() const { return true; } //c++11
};

class MyClass2
{
    string str;
public:
    MyClass2(string str) : str(str) { ; }
    explicit MyClass2(int iValue) 
    { 
        str.reserve(iValue);
    }
    explicit MyClass2(int iValue, int a, int b) { ; }
    friend ostream& operator<<(ostream& os, const MyClass2& my);
};

ostream& operator<<(ostream& os, const MyClass2& my)
{
    return os << my.str;
}

void writeMyClass2(MyClass2 my)
{
    cout << my << endl;
}

int main()
{
    std::cout << "Hello World!\n";
    MyClass my1(1);
    MyClass my2 = static_cast<MyClass>(1);
    writeMyClass2(static_cast<MyClass2>(2));
    MyClass my3(2);
    bool nb1 = static_cast<bool>(my3);
}