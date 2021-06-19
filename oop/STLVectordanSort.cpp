#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Mhs 
{ 
    private:
        string nim, nama; 
        int nilai; 
    public:
        Mhs(string inputNim, string inputNama, int inputNilai)
        {
            nim = inputNim;
            nama = inputNama;
            nilai = inputNilai;
        };
        void printData()
        {
            cout << nim << "-" << nama << "-" << nilai << endl;
        }
        string getNim()
        {
            return nim;
        }
        int getNilai()
        {
            return nilai;
        }
};

typedef pair<string, Mhs> nim1;
typedef pair<int, Mhs> nilai1;


bool urutNim(nim1 a, nim1 b)
{
    // string nimA = a.getNim();
    // string nimB = b.getNim();
    return a.first.compare(b.first) < 0;
}

bool urutNilai(nilai1 a, nilai1 b)
{
    return a.first > b.first;
}

int main()
{
    string nim, nama; 
    vector<Mhs> dataMhs;
    int nilai, n;
    cin >> n;
    while(n--)
    {
        cin >> nim >> nama >> nilai;
        Mhs input(nim, nama, nilai);
        dataMhs.push_back(input);
    }

    string urut;
    cin >> urut;
    cin >> nim;
    n = 0;

    vector<Mhs>::iterator it, f;
    vector<nim1> byNim;
    vector<nilai1> byNilai;

    if(urut.compare("URUTNIM") == 0)
    {
        for (it = dataMhs.begin(); it != dataMhs.end(); it++)
        {
            byNim.push_back(nim1(it->getNim(), *it));
        }
        
        sort(byNim.begin(), byNim.end(), urutNim);
    }

    if(urut.compare("URUTNILAI") == 0)
    {
        for (it = dataMhs.begin(); it != dataMhs.end(); it++)
        {
            byNilai.push_back(nilai1(it->getNilai(), *it));
        }
        
        sort(byNilai.begin(), byNilai.end(), urutNim);
    }

    for (it = dataMhs.begin(); it != dataMhs.end(); it++)
    {
        it->printData();
        if(it->getNim() == nim)
        {
             n = 1;
             f = it;
        }
    }
    
    if(n)
        f->printData();
    else
    {
            cout << "TIDAK ADA" << endl;
    }
    

    return 0;
}