// tuple.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <tuple>

int main()
{
    std::cout << "Hello World!\n";
    std::tuple<int, double, int> tuple1(2,3,4);
    std::get<0>(tuple1) = 7;
    std::cout << std::get<0>(tuple1) << std::get<1>(tuple1)<< std::get<2>(tuple1) << std::endl;
    int int1, int2;
    double double1=0;
    std::tie(int1, std::ignore, int2) = tuple1;

    std::cout << int1 << double1 << int2 << std::endl << std::endl;

    std::tuple<int&, double, int> tuple2(int1, 3, 4);
    std::cout << int1 << double1 << int2 << std::endl;
    std::get<0>(tuple2) = 9;
    std::cout << int1 << double1 << int2 << std::endl;
    int1 = 5;
    std::cout << std::get<0>(tuple2) << double1 << int2 << std::endl;

    std::tuple<int &, int> tuple3 = std::make_tuple(std::ref(int1), int2);
    //tie zawsze zwraca referencje, a w tym przykladzie potem jest to 
    //konwerotwane na int.
    std::tuple<int &, int> tuple4 = std::tie(int1, int2);
    std::cout << std::get<0>(tuple3) << std::get<1>(tuple3) << std::endl;
    int1 = 9;
    std::cout << std::get<0>(tuple4) << std::get<1>(tuple4) << std::endl;
}

