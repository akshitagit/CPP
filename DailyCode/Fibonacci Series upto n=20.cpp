#include <iostream>

using namespace std;
#define n 20
int main()
{
    int num=0, next_num=1, temp=0;
    cout<<0<<" "<<1;
    for(int i=0;i<20;i++)
    {
        temp=num;
        num=next_num;
        next_num=temp+num;
        cout<<" "<<next_num;
    }
    return 0;
}
