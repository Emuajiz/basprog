#include <iostream>
#include <set>
#include <string>
 
using namespace std;
 
int main()
{
    int n;
    string input;
    set<string> jual, sama;
    set<string>::iterator it;
    cin >> n;
    while (n--)
    {
        cin >> input;
        jual.insert(input);
        // cout << input << endl;
    }
     
    cin >> n;
    while (n--)
    {
        cin >> input;
        const string tes = input;
        it = jual.find(tes);
        if(*it == tes)
        {
            sama.insert(tes);
        }
    }
     
    int i = 0;
 
    for (it = sama.begin(); it != sama.end(); it++)
    {
        i++;
        if(i < sama.size())
            cout << *it << " ";
        else
            cout << *it << endl;
    }
 
    if(i == 0)    
        cout << "tidak ada kesamaan" << endl;
 
    return 0;
}