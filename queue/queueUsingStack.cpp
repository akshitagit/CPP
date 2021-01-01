#include<iostream>
#include<stack>
using namespace std;


int main(int argv, char *argc[])
{
    int t;
    stack <int> upper, back;
    cin >> t;
    while(t--)
    {
        int type;
        long int x;
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            upper.push(x);
        }
        else
        {
            if(back.empty())
            {
                while(upper.empty() == false)
                {
                    back.push(upper.top());
                    upper.pop();
                }
            }
            if(back.empty() == false)
            {
                if(type == 2)
                {
                    back.pop();
                }
                else if(type == 3)
                {
                    cout << back.top() << endl;
                }
            }
        }
    }
    return 0;
}