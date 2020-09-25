#include <stdio.h>

long long fact(int n);

int main()
{
    int n, k, num, i;
    long long term;

    printf("Enter number of rows : ");
    scanf("%d", &num);

    for(n=0; n<num; n++)
    {
        for(i=n; i<=num; i++)
            printf("%3c", ' ');
        for(k=0; k<=n; k++)
        {
            term = fact(n) / (fact(k) * fact(n-k));

            printf("%6lld", term);
        }

        printf("\n");
    }

    return 0;
}

long long fact(int n)
{
    long long factorial = 1ll;
    while(n>=1)
    {
        factorial *= n;
        n--;
    }
    return factorial;
}