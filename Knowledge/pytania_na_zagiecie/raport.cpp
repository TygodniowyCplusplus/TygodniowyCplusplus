#include <stdio.h>
#include <iostream>

int main()
{
	int tab[10];
	2[tab] = 4;
	*(2+tab) = 4;
	//a[b] = *(a+b) =*(b+a;
	//2[tab] = tab[2];
	
	std::cout << tab[-1] << std::endl;
	
	std::cout << tab[2] << std::endl;
    return 0;
}

#include <stdio.h>
#include <iostream>

int main()
{
	int tab[10];
	if(tab<:7:> == 7)
	{
		;
	}
	//c++17
	if(tab??(7??) == 7)
	{
		;
	}
	if(not true) //=(!true)
	{
		;
	}
    return 0;
    //'<:' = '['
    //{ = <%
    //??( = [
    //??) = ]
    //g++ main.cpp -std=c++17 -trigraphs
    //g++ main.cpp -std=c++14
    //bitor = |
}

#include <stdio.h>

void f()
{
	void d()
	{
		;
	}
}
int main()
{
	f();
    return 0;
}

//main.c
#include <stdio.h>

void f()
{
	void d()
	{
		;
	}
}
int main()
{
	f();
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <string>

void d()
{
	void f(int a);
}
int main()
{
	std::string str1("tt");
	std::cout << str1 << std::endl;
	std::string str2{"tt"};
	std::cout << str2 << std::endl;
	std::string str3{};
	str3 = "ee";
	std::cout << str3 << std::endl;
	/*std::string str4();
	str4 = "ee";
	std::cout << str4 << std::endl;*/
	int a{};
	a = 3;
	/*int a1();
	a1 = 3;*/
	
	void f(int a);
	int a1();
	//a1 = 8;
	d();
    return 0;
}


