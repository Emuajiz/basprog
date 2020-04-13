#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    float a, b, c;
    cin >> a >> b;
    c = 1.0 * a + b;
    cout << fixed;
    cout << setprecision(2);
    cout << c << endl;
    return 0;
}