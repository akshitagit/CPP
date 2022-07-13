#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int compare(string a, string b)
{
    string c = a+b;
    string d = b+a;
    if(c>d)
    return 1;
    else
    return 0;
    
}

int main() 
{

    int t;
    cin >> t;
    while(t!=0)
    {
        int n, i, j, sum=0;
        string temp;
        cin >> n;
        string a[n];
        for(i=0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a, a+n, compare);
        for(i=0;i<n;i++)
        {
            cout << a[i];
        }
        cout << "\n";
        t--;
    }

}
