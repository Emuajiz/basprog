#include <iostream>
#include <new>
using namespace std;

class A 
{
    public:
    void print() { cout << "A";}
};

class B:public A
{
    public:
    void print() { cout << "B";}
};

int main()
{
    A obj1;
    B obj2 = B();
    obj1.print();
    obj2.print();
    return 0;
}