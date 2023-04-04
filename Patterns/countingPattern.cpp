/*  Pattern is in the form of counting that is showing in the figure:-
1234
1234
1234
*/
#include <iostream>
using namespace std;
// code by abhishek Pandey;
int main()
{
    int n;
    cout << "Enter the max number of counting in the pattern" << endl;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
}