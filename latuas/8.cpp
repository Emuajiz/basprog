#include<iostream>
#include<new>

using namespace std;

class MyClass {
    public:
    MyClass() {cout << '*'; }
};

int main()
{
    MyClass *p1 = new MyClass[5];
    cout << endl;
    delete[] p1;

    return 0;
}