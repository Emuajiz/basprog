#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct mhs{
    char nim[10];
    int usia;
    int jk;
    float ipk;
};

int main()
{
    int n, m, x, y;
    mhs data[100];
    mhs tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].nim >> data[i].usia >> data[i].jk >> data[i].ipk;
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

        cout << data[i].nim << " " << data[i].usia << " " << data[i].jk << " " << data[i].ipk << endl;
    }

    return 0;
}