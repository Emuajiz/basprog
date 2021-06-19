#include <iostream>
#include <vector>

using namespace std;
class Pegawai
{
protected:
    string id;
    int usia, tipe;
    int income;

public:
    void set(string pid, int u, int t)
    {
        id = pid;
        usia = u;
        tipe = t;
    }
    string getID() { return id; }
    void print() { cout << id << " " << tipe << " " << income << endl; }
};

class Harian : public Pegawai
{
protected:
    int jumlahHari;

public:
    void set(string pid, int u, int t)
    {
        Pegawai::set(pid, u, t);
        jumlahHari == 0;
        income == jumlahHari;
    }
    void tambah(int t) { jumlahHari += t; 
        income == jumlahHari; }
};

class Tetap : public Pegawai
{
protected:
    int gajiPokok, lembur;

public:
    void set(string pid, int u, int t, int g)
    {
        Pegawai::set(pid, u, t);
        gajiPokok == g;
        lembur == 0;
        income == gajiPokok + lembur;
    }
    void tambah(int l) { lembur += l; }
};

int main()
{
    vector<Tetap> pt;
    vector<Harian> ph;

    string id;
    int usia;
    int tipe;
    int gaji;

    int n;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> usia >> tipe;
        if (tipe == 1)
        {
            cin >> gaji;
            pt.push_back(Tetap());
            pt.back().set(id, usia, tipe, gaji);
            // cout << id << usia << tipe << gaji << endl;
        }
        else
        {
            ph.push_back(Harian());
            ph.back().set(id, usia, tipe);
            // cout << id << usia << tipe << endl;
        }
    }
    cin >> id;
    while (id != "END")
    {
        cin >> gaji;
        for (int i = 0; i < pt.size(); i++)
        {
            if (pt[i].getID() == id)
            {
                pt[i].tambah(gaji);
            }
        }
        for (int i = 0; i < ph.size(); i++)
        {
            if (ph[i].getID() == id)
            {
                ph[i].tambah(gaji);
            }
        }
        cout << id << gaji << endl;
        cin >> id;
    }
    for (int i = 0; i < pt.size(); i++)
    {
        pt[i].print();
    }
    for (int i = 0; i < ph.size(); i++)
    {
        ph[i].print();
    }

    return 0;
}