#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

class Person
{
    private:
        string nama;
        int usia, tinggi;
        double berat;
    
    public:
        int getTInggi()
        {
            return tinggi;
        }

        void init(string a, int b, int c, double d)
        {
            nama = a;
            usia = b;
            tinggi = c;
            berat = d;
        }

        void print()
        {
            cout << nama << " " << usia << " " << tinggi << " " << berat << endl;
        }

        void printOnlyNamaAndUsia()
        {
            cout << nama << " " << usia << endl;
        }
};

int main()
{
    int n, usia, tinggi, sumOfTInggi = 0, aboveAverage = 0;
    double berat, averageOfTinggi;
    string nama;

    Person data[100];
    cin >> n;

    cout << fixed;
    cout << setprecision(1);

    for (int i = 0; i < n; i++)
    {
        cin >> nama >> usia >> tinggi >> berat;
        data[i].init(nama,usia,tinggi,berat);
        data[i].printOnlyNamaAndUsia();
        sumOfTInggi += data[i].getTInggi();
    }
    
    averageOfTinggi = (double) sumOfTInggi / n;
    
    cout << fixed;
    cout << setprecision(2);

    cout << averageOfTinggi << endl;

    for (int i = 0; i < n; i++)
    {
        if(data[i].getTInggi() > averageOfTinggi)
            aboveAverage++;
    }
    
    cout << aboveAverage << endl;

    return 0;
}