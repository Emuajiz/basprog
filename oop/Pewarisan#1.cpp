#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Poligon 
{
    protected:
        vector<double> x;
        vector<double> y;
        int nEdge;

        double distance(int a, int b)
        {
            double xSelisih, ySelisih;
            xSelisih = x[a] - x[b];
            ySelisih = y[a] - y[b];
            return sqrt((xSelisih * xSelisih) + (ySelisih * ySelisih));
        }

    public:
        void set()
        {
            x.clear();
            y.clear();
            double xInput, yInput;
            for (int i = 0; i < nEdge; i++)
            {
                cin >> xInput >> yInput;
                x.push_back(xInput);
                y.push_back(yInput);
            }
            
        }
        void print()
        {
            cout.precision(2);
            cout << fixed;
            cout << '[' << x[0] << ',' << y[0] << ']';
            cout << '-';
            cout << '[' << x[nEdge - 1] << ',' << y[nEdge - 1] << ']' << endl;
        }
        double keliling()
        {
            double total = 0;
            for (int i = 0; i < nEdge; i++)
            {
                total += distance(i, (i+1) % nEdge);
            }
            return total;
        }
};

class Segitiga:public Poligon
{
    public:
        Segitiga() {nEdge = 3;}
        double luas()
        {
            double det = x[0]*y[1] - x[1]*y[0] + x[1]*y[2] - x[2]*y[1] + x[2]*y[0] - x[0]*y[2];
            if(det < 0)
                det *= -1;
            return det/2;
        }
};

class Segiempat:public Poligon
{
    public:
        Segiempat() {nEdge = 4;}
        double luas()
        {
            double s = keliling() / 4.0;
            return s*s;
        }
};

int main()
{
    // vector<Segitiga> segi3;
    // vector<Segiempat> segi4;
    Segitiga segi3In[100];
    Segiempat segi4In[100];
    double luas[2], ave[2]; 
    int n, banyak[2];

    cin >> n;
    luas[0] = 0;
    for (int i = 0; i < n; i++)
    {
        segi3In[i].set();
        luas[0] += segi3In[i].luas();
        // segi3.push_back(segi3In);
    }

    ave[0] = luas[0]/n;
    banyak[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if(segi3In[i].luas() > ave[0])
            banyak[0]++;
    }
    
    cin >> n;
    luas[1] = 0;
    for (int i = 0; i < n; i++)
    {
        segi4In[i].set();
        luas[1] += segi4In[i].luas();
        // segi4.push_back(segi4In);
    }

    ave[1] = luas[1]/n;
    banyak[1] = 0;
    for (int i = 0; i < n; i++)
    {
        if(segi4In[i].luas() > ave[1])
            banyak[1]++;
    }
    
    cout.precision(2);
    cout << fixed;
    cout << ave[0] << ' ' << ave[1] << endl;
    cout << banyak[0] << ' ' << banyak[1] << endl;
}