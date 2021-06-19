#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
protected:
    string nama; // nama
    char jk;     // jenis kelamin
    int usia;    // usia (tahun)
    string kota; // kota lahir
public:
    void set(string n, char j, int u, string k)
    {
        nama = n;
        jk = j;
        usia = u;
        kota = k;
    }
    string getNama();
    char getSex();
    int getUsia();
    string getKota();
};

class Male : public Person
{
public:
    void set(string n, int u, string k)
    {
        nama = n;
        jk = 'L';
        usia = u;
        kota = k;
    }
};

class Female : public Person
{
public:
    void set(string n, int u, string k)
    {
        nama = n;
        jk = 'P';
        usia = u;
        kota = k;
    }
};

string Person::getNama()
{
    return nama;
}

char Person::getSex()
{
    return jk;
}

int Person::getUsia()
{
    return usia;
}

string Person::getKota()
{
    return kota;
}

template <typename J> 
double average(vector<J> I) 
{ 
    int total;
    total = 0;
    for (int i = 0; i < I.size(); i++)
    {
        total += I[i].getUsia();
    }
    double ave = (double) total / I.size();
    return ave;
}

template <typename J> 
int dibawah(vector<J> I) 
{
    double ave = average<J>(I);
    int below = 0;
    for (int i = 0; i < I.size(); i++)
    {
        if(I[i].getUsia() < ave)
            below++;
    }
    return below;
}

int main()
{
    string input, nama, tempat_lahir;
    char jk, jl, jp;
    jl = jp = 0;
    int usia;
    vector<Male> L;
    vector<Female> P;
    while (getline(cin, input))
    {
        nama = input.substr(0, 25);
        jk = input[25];
        char us[2];
        us[0] = input[26];
        us[1] = input[27];
        usia = atoi(us);
        tempat_lahir = input.substr(28, 24);
        if (jk == 'L')
        {
            // cout << nama << " L " << usia << ' ' << tempat_lahir << endl;
            // Male m;
            L.resize(jl+1);
            L[jl].set(nama, usia, tempat_lahir);
            // L.push_back(m);
            jl++;
        }
        else
        {
            // cout << nama << " P " << usia << ' ' << tempat_lahir << endl;
            // Female f;
            P.resize(jp+1);
            P[jp].set(nama, usia, tempat_lahir);
            // P.push_back(f);
            jp++;
        }
    }
    
    cout.precision(2);
    cout << fixed;
    cout << "L " << L.size() << ' ' << average<Male>(L) << ' ' << dibawah<Male>(L) << endl;
    cout << "P " << P.size() << ' ' << average<Female>(P) << ' ' << dibawah<Female>(P) << endl;

    return 0;
}