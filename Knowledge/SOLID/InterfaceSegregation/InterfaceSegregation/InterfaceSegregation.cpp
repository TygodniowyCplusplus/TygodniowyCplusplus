#include <iostream>
#include <string>
using namespace std;

//Interface Segregation Principle 

//Zasada segregacji interfejsów

/*class IKlientPoczty
{
public:
    virtual void podajePrzesylke() = 0;
    virtual void placiZaPrzesylke() = 0;
};

class KlientPocztu: public IKlientPoczty
{
public:
    void podajePrzesylke() override
    {
        cout << "proszę tu jest przesylka" << endl;
    }
    void placiZaPrzesylke() override
    {
        cout << "proszę tu jest zaplata za przesylke" << endl;
    }
};*/

///////////////////////////////////////////////////////////
/*class IKlientPoczty
{
public:
    virtual void podajePrzesylke() = 0;
    virtual void placiZaPrzesylke() = 0;
    virtual void podajeNIP() = 0;
};

class KlientPoczty: public IKlientPoczty
{
public:
    void podajePrzesylke() override
    {
        cout << "proszę tu jest przesylka" << endl;
    }
    void placiZaPrzesylke() override
    {
        cout << "proszę tu jest zaplata za przesylke" << endl;
    }
};

class KlientBiznesowyPoczty : public IKlientPoczty
{
public:
    void podajePrzesylke() override
    {
        cout << "proszę tu jest przesylka" << endl;
    }
    void placiZaPrzesylke() override
    {
        cout << "proszę tu jest zaplata za przesylke" << endl;
    }
    void podajeNIP() override
    {
        cout << "proszę tu jest moj NIP" << endl;
    }
};*/

///////////////////////////////////////////////////////////

class IKlientPoczty
{
public:
    virtual void podajePrzesylke() = 0;
    virtual void placiZaPrzesylke() = 0;
};

class IKlientBiznesowyPoczty
{
public:
    virtual void podajeNIP() = 0;
};

class KlientPoczty : public IKlientPoczty
{
public:
    void podajePrzesylke() override
    {
        cout << "proszę tu jest przesylka" << endl;
    }
    void placiZaPrzesylke() override
    {
        cout << "proszę tu jest zaplata za przesylke" << endl;
    }
};

class KlientBiznesowyPoczty : public IKlientPoczty, public IKlientBiznesowyPoczty
{
public:
    void podajePrzesylke() override
    {
        cout << "proszę tu jest przesylka" << endl;
    }
    void placiZaPrzesylke() override
    {
        cout << "proszę tu jest zaplata za przesylke" << endl;
    }
    void podajeNIP() override
    {
        cout << "proszę tu jest moj NIP" << endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}