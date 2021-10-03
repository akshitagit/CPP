#include <iostream>
using namespace std;

void cyclicSort()
{
    int inp[] = {5, 3, 4, 1, 2, 7, 9, 6, 8};
    int length = (sizeof(inp) / sizeof(inp[0]));
    int temp;
    int i=0;
    while(i<length)
    {
        int correct=inp[i]-1;
        if (inp[correct] != inp[i])
        {
            temp = inp[correct];
            inp[correct]=inp[i];
            inp[i]=temp;
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < length; i++)
    {
        cout << inp[i] << " ";
    }
}

int main()
{
    cyclicSort();
    return 0;
}