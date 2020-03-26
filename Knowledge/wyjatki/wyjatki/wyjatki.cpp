// wyjatki.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <stdexcept>

using namespace std;

struct MyStruct
{
    int b = 0;
};
int main()
{
    std::cout << "Hello World!\n";

    try
    {
        try
        {
            cout << "polecenie 1\n";
            MyStruct my;
            my.b = 3;
            throw logic_error("taki sobie logiczny wyjatek");
            //throw runtime_error("taki sobie runtime error");
            cout << "polecenie 2\n";
        }
        catch (logic_error & e)
        {
            cout << "zlapano logic_error " << e.what() << endl;
            throw;
        }
        catch (exception & e)
        {
            cout << "zlapano jakis standardowy wyjatek: " << e.what() << endl;
        }
        catch (MyStruct & my)
        {
            cout << "zlapano MyStruct " << my.b << endl;
        }
        catch (...)
        {
            cout << "zlapano nie okreslony wyjatek\n";
        }
    }
    catch (exception & e)
    {
        cout << "koncowe: " << e.what() << endl;
    }
   
}
