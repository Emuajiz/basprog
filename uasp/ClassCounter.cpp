#include <iostream>

using namespace std;

class Counter
{
private:
    int awal;

public:
    void set(int inp)
    {
        if (inp > 0)
            awal = inp;
        else
            awal = 0;
    }
    void tambah() { awal++; }
    void kurang()
    {
        if (awal != 0)
            awal--;
    }
    void print() { cout << awal << endl; }
};

int main()
{
    Counter count;
    int n;
    int input;
    cin >> n;
    while (n != -9)
    {
        switch (n)
        {
        case 0:
            cin >> input;
            count.set(input);
            break;
        case 1:
            count.tambah();
            break;
        case -1:
            count.kurang();
            break;
        case 9:
            count.print();
            break;
        case -9:
            count.print();
            return 0;
            break;
        default:
            break;
        }

        cin >> n;
    }
    return 0;
}