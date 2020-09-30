#include<stdio.h>
#define N 8     //change this value according to the no. of elements in array p

int maxPrice(int p[], int n)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1; i<=n; ++i)
    {
        int max = 0;
        for(int j=0; j<i; ++j)
        {
            int x = dp[j] + p[i-j-1];
            if(x > max)
                max = x;
        }
        dp[i] = max;
    }
    for(int i=0; i<=n; ++i)
        printf("%d ", dp[i]);
    printf("\n");
    return dp[n];
}
int main()
{
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20};     //array of prices: p[i] represents the cost of rod of length i (one-based indexing)
    printf("The maximum price obtained is: %d\n", maxPrice(p, N));
    return 0;
}