
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <new>
using namespace std;

class NIM
{
    string value;

public:
    NIM() { value = ""; }
    void setNIM(string p) { value = p; }
    char getFakultas();  // Mendapatkan kode Fakultas
    string getNIM();     // Mendapatkan nilai NIM
    string getProdi();   // Mendapatkan kode Program Studi
    int getTahunMasuk(); // Mendapatkan Tahun Masuk
};

/* IMPLEMENTASI FUNGSI ANGGOTA
...................
...................
*/

char NIM::getFakultas()
{
    return value[0];
}

string NIM::getNIM()
{
    return value;
}
string NIM::getProdi()
{
    return value.substr(0,3);
}
int NIM::getTahunMasuk()
{
    char a[2];
    a[0] = value[3];
    a[1] = value[4];
    int taun = atoi(a);
    if(taun < 63)
        taun += 2000;
    else
    {
        taun += 1900;
    }
    
    return taun;
}

int main()
{
    NIM *mhs = new NIM;
    char st[10];
    while (scanf("%s", st) != EOF)
    {
        mhs->setNIM(st);
        cout << mhs->getNIM() << " " << mhs->getFakultas() << " "
             << mhs->getProdi() << " " << mhs->getTahunMasuk() - 1963 << endl;
    }
    return 0;
}