#include <iostream>
#include <cmath>

using namespace std;

class Titik
{
    double x, y;

public:
    void set(double p, double q)
    {
        x = p;
        y = q;
    }
    double getX() { return x; }
    double getY() { return y; }
    void print() { cout << "(" << x << "," << y << ")"; }
};

class Lingkaran
{
    Titik p;
    double r;

public:
    void set(double px, double py, double jari)
    {
        p.set(px, py);
        r = jari;
    }
    Titik getPusat() { return p; }
    double getR() { return r; }
    double getLuas() { return 3.14 * r * r; }
    double getKeliling() { return 2 * 3.14 * r; }
    // ...
};

class Segitiga
{
    Titik x, y, z;

public:
    // ...
    void set(double ax, double ay, double bx, double by, double cx, double cy)
    {
        x.set(ax, ay);
        // x.print();
        y.set(bx, by);
        // y.print();
        z.set(cx, cy);
        // z.print();
    }
    double getLuas()
    {
        double xl[3] = {x.getX(), y.getX(), z.getX()};
        double yl[3] = {y.getY(), y.getY(), y.getY()};
        double det = xl[0] * yl[1] - xl[1] * yl[0] + xl[1] * yl[2] - xl[2] * yl[1] + xl[2] * yl[0] - xl[0] * yl[2];
        if (det < 0)
            det *= -1;
        cout << "DET: " << xl[0] << endl;
        return det / 2;
    }
    double getKeliling()
    {
        double xab, yab, xbc, ybc, xac, yac;
        xab = x.getX() - y.getX();
        yab = x.getY() - y.getY();
        xbc = y.getX() - z.getX();
        ybc = y.getY() - z.getY();
        xac = x.getX() - z.getX();
        yac = x.getY() - z.getY();
        double ab, bc, ac;
        ab = sqrt(xab*xab+yab+yab);
        bc = sqrt(xbc*xbc+ybc+ybc);
        ac = sqrt(xac*xac+yac+yac);
        double keliling = ab+bc+ac;
        return keliling;
    }
};

int main()
{
    int n, m;
    double x, y, r, ax, ay, bx, by, cx, cy;
    cin >> n >> m;
    Segitiga s[100];
    Lingkaran l[100];
    // double totalS[2], totalL[2];
    double totalS[2] = {0};
    double totalL[2] = {0};
    int banyakLuas[2], BanyakKeliling[2];
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> r;
        l[i].set(x, y, r);
        // cout << l[i].getLuas() << endl;
        // cout << l[i].getKeliling() << endl;
        totalL[0] += l[i].getLuas();
        totalL[1] += l[i].getKeliling();
    }
    for (int i = 0; i < m; i++)
    {

        cin >> ax >> ay >> bx >> by >> cx >> cy;
        // cout << ' ' << ax << ' ' << ay << ' ' << bx << ' ' << by << ' ' << cx << ' ' << cy << endl;
        s[i].set(ax, ay, bx, by, cx, cy);
        // cout << s[i].getLuas() << endl;
        // cout << s[i].getKeliling() << endl;
        totalS[0] += s[i].getLuas();
        totalS[1] += s[i].getKeliling();
    }

    banyakLuas[0] = BanyakKeliling[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if(l[i].getLuas() > totalL[0] / n)
            banyakLuas[0]++;
        if(l[i].getKeliling() > totalL[1] / n)
            BanyakKeliling[0]++;
    }
    
    banyakLuas[1] = BanyakKeliling[1] = 0;
    for (int i = 0; i < m; i++)
    {
        if(s[i].getLuas() > totalS[0] / n)
            banyakLuas[1]++;
        if(s[i].getKeliling() > totalS[1] / n)
            BanyakKeliling[1]++;
    }

    cout << banyakLuas[0] << ' ' << banyakLuas[1] << endl;
    cout << BanyakKeliling[0] << ' ' << BanyakKeliling[1] << endl;

    return 0;
}