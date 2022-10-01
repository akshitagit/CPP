#include <iostream>
using namespace std;
int main()
{
    char ch;
    // ch = cin.get();
    int n = 0;
    int c = 0;
    int s = 0;
    while (ch != '$')
    {

        ch = cin.get();
        if (ch >= 'a' && ch <= 'z')
        {
            c++;
        }
        else if (ch >= '0' && ch <= '9')
        {
            n++;
        }
        else if (ch == 32)
        {
            s++;
        }
        else if (ch == '\t' || ch == '\n')
        {
            s++;
        }
    }
    cout << c << " " << n << " " << s << endl;
}
