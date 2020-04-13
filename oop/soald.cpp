#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long long int angka, ldigit, digitangka[10] = {0}, i = 0, j, possible = 0;
    cin >> angka;
    while(angka)
    {
        digitangka[i] = angka % 10;
        angka /= 10;
        i++;
    }

    i--;

    for (j = 0; j < i; j++)
    {
        // cout << digitangka[j] << ' ';
        if(digitangka[j] > digitangka[j+1])
        {
            possible = 1;
            int tmp = digitangka[j];
            digitangka[j] = digitangka[j + 1];
            digitangka[j + 1] = tmp;
            break;
        }
    }

    // cout << endl << i << ' ' << j << endl;

    sort(digitangka, digitangka + j + 1, greater<int>());
    angka = 0;
    for (i = 9; i >= 0; i--)
    {
        // cout << digitangka[i] << ' ';
        angka *= 10;
        angka += digitangka[i];
    }
    
    if(possible)
        cout << angka << endl;
    else
        cout << 0 << endl;

    return 0;
}