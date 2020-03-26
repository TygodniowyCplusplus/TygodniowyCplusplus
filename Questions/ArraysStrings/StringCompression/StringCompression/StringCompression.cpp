// StringCompression.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//String Compression: Implement a method to perform basic 
//string compression using the counts of repeated characters. 
//For example, the string aabcccccaaa would become a2blc5a3. 
//If the "compressed "string would not become smaller than 
//the original string, your method should return the original 
//string. You can assume the string has only uppercase and 
//lowercase letters (a - z).

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string commpres(string str)
{
    string strOut;
    int count = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        ++count;
        if (i < str.length() - 1)
        {
            if (str[i + 1] != str[i])
            {
                strOut += str[i] + to_string(count);
                count = 0;
            }
        }
        else
        {
            strOut += str[i] + to_string(count);
        }
    }
    return strOut.length() < str.length() ? strOut : str;
}

string commpres2(string str)
{
    string strOut;
    int count = 0;
    //int adress = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        ++count;
        if (i < str.length() - 1)
        {
            if (str[i + 1] != str[i])
            {
                strOut += str[i];
                strOut += to_string(count);
                /*if (adress != (int)&strOut[0])
                {
                    adress = (int)&strOut[0];
                    cout << adress << endl;
                }*/
                count = 0;
            }
        }
        else
        {
            strOut += str[i] + to_string(count);
        }
    }
    return strOut.length() < str.length() ? strOut : str;
}

string commpres3(string str)
{
    int compressedLength = 0;
    int countConsecutive = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        ++countConsecutive;
        if (i + 1 >= str.length() || str[i] != str[i + 1]) 
        {
            compressedLength += 1 + 
                to_string(countConsecutive).length();
            countConsecutive = 0;
        }
    }
    if (compressedLength >= str.length())
        return str;
    string strOut;
    strOut.reserve(compressedLength);
    int count = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        ++count;
        if (i < str.length() - 1)
        {
            if (str[i + 1] != str[i])
            {
                strOut += str[i];
                strOut += to_string(count);
                count = 0;
            }
        }
        else
        {
            strOut += str[i] + to_string(count);
        }
    }
    return strOut;
}

int main()
{
    std::cout << "Hello World!\n";
    string str = "aabcccccaaa";
    cout << commpres(str) << endl;
    cout << commpres2(str) << endl;
    cout << commpres3(str) << endl;

    str = "aabcccccaaa";
    //str.size ~ 11000000;
    for (int i = 0; i < 20; ++i)
        str += str;
    commpres(str); //159ms
    commpres2(str); //107ms
    commpres3(str); //147ms
}
