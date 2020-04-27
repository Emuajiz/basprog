#include <iostream>
#include <vector>
using namespace std;

class Data
{
    private:
        vector<int> arr1, arr2;
        int total[2], deleted;
        double average[2];

    public:
        Data(){
            deleted = 0;
            total[0] = 0;
            total[1] = 0;
        }

        void getInput();

        void hapus(int pos) {
            vector<int>::iterator it = arr2.begin();
            if(deleted < arr1.size())
            {
                arr2.erase(it + pos - 1 - deleted, it + pos - deleted);
                deleted++;
            }
        }

        void printArr1();
        void printArr2();
        int getSizeArr1();
        int getSizeArr2();
        double getAveArr1();
        double getAveArr2();
};

void Data::getInput()
{
    int get;
    while(true)
    {
        cin >> get;
        if(get == -9) break;
        arr1.push_back(get);
        arr2.push_back(get);
    }
}

int Data::getSizeArr1()
{
    return arr1.size();
}

int Data::getSizeArr2()
{
    return arr2.size();
}

double Data::getAveArr1()
{
    vector<int>::iterator it = arr1.begin();
    total[0] = 0;
    for (it; it != arr1.end(); it++)
    {
        total[0] += *it;
    }
    if(arr1.size())
        average[0] = (double) total[0] / (double) arr1.size();
    else
        average[0] = -9.99;
    return average[0];
}

double Data::getAveArr2()
{
    vector<int>::iterator it = arr2.begin();
    total[1] = 0;
    for (it; it != arr2.end(); it++)
    {
        total[1] += *it;
    }
    if(arr2.size())
        average[1] = (double) total[1] / (double) arr2.size();
    else
        average[1] = -9.99;
    return average[1];
}

void Data::printArr1()
{
    vector<int>::iterator it = arr1.begin();
    for (it; it != arr1.end(); it++)
    {
        cout << *it << endl;
    }
}

void Data::printArr2()
{
    vector<int>::iterator it = arr2.begin();
    for (it; it != arr2.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    int get;
    Data angka;
    angka.getInput();

    cout.precision(2);

    while(true)
    {
        cin >> get;
        if(get == -9) break;
        angka.hapus(get);
    }

    cout << angka.getSizeArr1() << " " << angka.getSizeArr2() << endl;
    cout << fixed << angka.getAveArr1() << " " << angka.getAveArr2() << endl;

    return 0;
}