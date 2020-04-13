#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int bungkus, makan, tukar, sisa;
    cin >> makan;
    bungkus = makan;
    while(bungkus > 4){
        tukar = bungkus / 5;
        sisa = bungkus % 5;
        makan += tukar;
        bungkus = tukar + sisa;
    }
    cout << makan << endl;
    return 0;
}