#include<bits/stdc++.h>
using namespace std;

int main()
{
    int rows, i, space, k, c = 1;
    cout<<"Enter the number of rows to be printed :"<<endl;
    scanf("%d", &rows);
    for (i = 0; i < rows; i++)
    {
        for (space = 1; space <= rows - i; space++)
        {
            cout<<"  ";
        }
        for (k = 0; k <= i; k++)
        {
            if (k == 0 || i == 0)
            {
                c = 1;
            }
            else
            {
                c = c * (i - k + 1) / k;
            }
            printf("% 4d", c);
        }

        cout<<endl;
    }
    return 0;
}
