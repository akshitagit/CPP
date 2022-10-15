#include<stdio.h>
int findsqrt(int n)
{
    for(int i=1;i<=n/2;i++)
    {
        if((i*i)>n)
        return i-1;
        else if((i*i)==n)
        return i;
    }  
}
int main()
{
    int n;
    printf("\nEnter the number: ");
    scanf("%d",&n);
    printf("\nThe floor of sqrt of %d is %d",n,findsqrt(n));

}
