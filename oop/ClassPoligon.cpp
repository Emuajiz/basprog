#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Poligon{
    private:
        vector<double> x, y;
        int nEdge;

    public:
        void set()
        {
            int n;
            double xInput, yInput;
            cin >> n;
            nEdge = n;
            for (int i = 0; i < n; i++)
            {
                cin >> xInput >> yInput;
                x.push_back(xInput);
                y.push_back(yInput);
            }
        }

        void print()
        {
            double xAwal = x[0];
            double yAwal = y[0];
            double xAkhir = x[nEdge-1];
            double yAkhir = y[nEdge-1];
            cout.precision(2);
            cout << fixed;
            cout << "[" << x.front() << "," << y.front()
                 << "]-[" << x.back() << "," << y.back()
                 << "]" << endl;
        }

        double keliling()
        {
            double keliling = 0;

            for (int i = 0; i < nEdge; i++)
            {
                double xSelisih, ySelisih;
                xSelisih = x[i] - x[(i+1)%nEdge];
                ySelisih = y[i] - y[(i+1)%nEdge];
                keliling += sqrt((xSelisih*xSelisih) + (ySelisih*ySelisih));
            }
            
            return keliling;
        }

};

int main()
{
    Poligon p;

    p.set();
    p.print();

    cout.precision(2);

    cout << fixed << p.keliling() << endl;
    
    return 0;
}