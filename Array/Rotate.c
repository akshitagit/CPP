// Rotating the array by 3 position to right
//Time COmplexity in O(n)
#include <stdbool.h> 
#include <stdio.h> 

void rotate(int arr[], int n)
{
    int x[n];
    for(int i=0;i<n;i++)
    {
        x[i]=arr[i];
    }
    int a=arr[n-3], b=arr[n-2], c=arr[n-1];

    for(int i=n-4;i>=0;i--)
    {
        arr[i+3]=x[i];
    }

    arr[0]=a;
    arr[1]=b;
    arr[2]=c;

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() 
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    rotate(arr,n);
}