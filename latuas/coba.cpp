#include <iostream>

using namespace std;

class ShoeType
{
    public:
    char style;
    double price;
};

class B
{
    int a;
};

int main()
{
    ShoeType shoe1, shoe2;
    shoe1.style = 'A';
    shoe1.price = 99.99;
    cout << shoe1.style << " Rp" << shoe1.price;
    B shoe1;
    shoe2 = shoe1;

    shoe2.price = shoe1.price / 9;
    cout << shoe2.style << " Rp" << shoe2.price;
}