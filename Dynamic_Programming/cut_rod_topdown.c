#include<stdio.h>
#define N 8     //change this value according to the no. of elements in array p

int maxPrice(int p[], int n, int r[])
{
    if(r[n] >= 0)
        return r[n];
    int max = 0;
    for(int i=0; i<n; ++i)
    {
        int x = p[i] + maxPrice(p,n-1-i, r);
        if(x > max)
            max = x;
    }
    r[n] = max;
    return max;
}
int main()
{
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20};     //array of prices: p[i] represents the cost of rod of length i (one-based indexing)
    int r[N+1];
    for(int i=0; i<=N; ++i)
        r[i] = -1;
    r[0] = 0;
    printf("The maximum price obtained is: %d\n", maxPrice(p, N, r));
}