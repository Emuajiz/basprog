#include <iostream>
#include <utility>
using namespace std;

class A
{
private:
    int a = 2;

protected:
    pair<int, int> dt;

public:
    A() { print(); }
    A(int a, int b) { dt = make_pair(a, b); }
    void print() { cout << "(" << dt.first << "," << dt.second << ")"; }
    void printA() { cout << a; }
};

class B : public A
{
public:
    B() { print(); }
    void printB() { printA(); }
};

int main()
{
    A a(4, 5);
    B b;
    a.print();
    a.printA();
    b.printA();
    b.printB();
    return 0;
}