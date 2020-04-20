#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

class Mhs
{
    private:
        string nim;
        int usia;
        int jk;
        float ipk;
    
    public:
        void setNim(string input)
        {
            nim.assign(input);
        }
        
        void setUsia(int input)
        {
            usia = input;
        }
        
        void setJK(int input)
        {
            jk = input;
        }
        
        void setIPK(float input)
        {
            ipk = input;
        }

        
        string getNim()
        {
            return nim;
        }
        
        int getUsia()
        {
            return usia;

        }
        
        int getJK()
        {
            return jk;
        }
        
        float getIPK()
        {
            return ipk;
        }
};

int main()
{
    int n, m, x, y, usia, jk;
    float ipk;
    string nim;
    Mhs data[100], tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nim >> usia >> jk >> ipk;
        data[i].setNim(nim);
        data[i].setUsia(usia);
        data[i].setJK(jk);
        data[i].setIPK(ipk);
        // cout << data[i].getNim() << " " << data[i].getUsia() << " " << data[i].getJK() << " " << data[i].getIPK() << endl;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        tmp = data[x-1];
        data[x-1] = data[y-1];
        data[y-1] = tmp;
    }
    
    
    for (int i = 0; i < n; i++)
    {
        cout << fixed;
        cout << setprecision(2);
        
        cout << data[i].getNim() << " " << data[i].getUsia() << " " << data[i].getJK() << " " << data[i].getIPK() << endl;
    }

    return 0;
}