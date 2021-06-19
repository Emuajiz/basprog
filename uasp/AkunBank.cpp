#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class Akun
{
protected:
    string depan, belakang;
    int trf;

public:
    Akun()
    {
        depan = "";
        belakang = "";
        trf = 1;
    }
    Akun(string a, string b)
    {
        depan = a;
        belakang = b;
        trf = 1;
    }
    void set(string a, string b)
    {
        depan = a;
        belakang = b;
    }
    void cetak() { cout << depan << ' ' << belakang << ' ' << trf << endl; }
    string getA()
    {
        return depan;
    }
    string getB()
    {
        return belakang;
    }
    void tambah()
    {
        trf++;
    }
};

int bandingAkun(Akun& lhs, Akun& rhs)
{
    if (rhs.getA().compare(lhs.getA()) == 0)
    {
        return rhs.getB().compare(lhs.getB()) > 0;
    }
    else
        return rhs.getA().compare(lhs.getA()) > 0;
}

int main()
{
    int testCase, n;
    unsigned int i;
    string a, b;
    vector<Akun> akun;
    cin >> testCase;
    // cout << testCase << endl;
    while (testCase--)
    {
        cin >> n;
        // cout << n << endl;
        while (n--)
        {
            cin >> a >> b;
            // cek ada yang sama ga
            for (i = 0; i < akun.size(); i++)
            {
                if (akun[i].getA() == a && akun[i].getB() == b)
                {
                    akun[i].tambah();
                    break;
                }
            }
            if (i == akun.size())
            {
                akun.push_back(Akun(a, b));
            }
        }
        sort(akun.begin(), akun.end(), bandingAkun);
        for (i = 0; i < akun.size(); i++)
        {
            akun[i].cetak();
        }
        if (testCase)
            cout << endl;
        akun.clear();
    }
    return 0;
}