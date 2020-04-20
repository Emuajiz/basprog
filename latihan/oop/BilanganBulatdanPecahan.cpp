#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    long long int a,b;
    long double c;
    
    cout << fixed;
    cout << setprecision(2);

    cin >> a >> b >> c;
    cout << a << " " << c << " " << b << endl;
    return 0;
}