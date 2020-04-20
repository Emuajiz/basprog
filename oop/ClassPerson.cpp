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

        
        double getBerat()
        {
            return berat;
        }

        double getIMT()
        {
            return (double) berat / (tinggi * tinggi / 10000.0);
        }

        string getStatusGizi()
        {
            double imt = getIMT();
            if(imt < 17.0)
                return "sangat kurus";
            else if(imt < 18.5)
                return "kurus";
            else if(imt < 25.0)
                return "normal";
            else if(imt < 28.0)
                return "gemuk";
            else
                return "sangat gemuk";
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
            cout << nama << " " << usia << " " << tinggi << " " << berat << " " << getIMT() << " " << getStatusGizi() << endl;
        }

        void printOnlyNamaAndUsia()
        {
            cout << nama << " " << usia << endl;
        }
};

int main()
{
    int n, usia, tinggi, sumOfTInggi = 0, aboveAverage = 0, status[5] = {0};
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
        sumOfTInggi += data[i].getTInggi();
    }
    
    averageOfTinggi = (double) sumOfTInggi / n;
    
    cout << fixed;
    cout << setprecision(2);

    for (int i = 0; i < n; i++)
    {
        data[i].print();
        if(data[i].getTInggi() > averageOfTinggi)
            aboveAverage++;
        if(data[i].getIMT() < 17.0)
            status[0]++;
        else if(data[i].getIMT() < 18.5)
            status[1]++;
        else if(data[i].getIMT() < 25.0)
            status[2]++;
        else if(data[i].getIMT() < 28.0)
            status[3]++;
        else
            status[4]++;
    }

    cout << averageOfTinggi << endl;
    
    cout << aboveAverage << endl;

    cout << status[0] << " " << status[1] << " " << status[2] << " " << status[3] << " " << status[4] << endl;

    return 0;
}