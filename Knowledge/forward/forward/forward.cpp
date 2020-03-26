// forward.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;
//C++11

//lvalue rvalue
class MyClass
{
public:
    int* ptr = nullptr;
    int size = 0;
    string str = "";
    MyClass()
        : size(0), str(""), ptr(nullptr) {
        ;
    }
    MyClass(int size, string str)
        : size(size), str(str) {
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = i + 1;
        }
    }
    MyClass(MyClass& other)
        : size(other.size), str(other.str) {
        if (&other != this)
        {
            ptr = new int[size];
            for (int i = 0; i < size; i++)
            {
                ptr[i] = other.ptr[i];
            }
        }
    }
    MyClass(MyClass&& other) noexcept
        : size(other.size), str(move(other.str)) {
        if (&other != this)
        {
            ptr = other.ptr;
            other.ptr = nullptr;
            other.size = 0;
        }
    }
    MyClass& operator=(MyClass& other) {
        if (&other != this)
        {
            size = other.size;
            str = other.str;
            delete[] ptr;
            ptr = new int[size];
            for (int i = 0; i < size; i++)
            {
                ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }
    MyClass& operator=(MyClass&& other) noexcept {
        if (&other != this)
        {
            size = other.size;
            other.size = 0;
            str = move(other.str);
            delete[] ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    ~MyClass() {
        delete[] ptr;
    }

};

//std::forward

template<typename T> T create(T&& t) {
    return T(forward<T>(t));
}

int main()
{
    std::cout << "Hello World!\n";
    MyClass my(10, "my");
    MyClass my2 = create(move(my));

    return 0;
}