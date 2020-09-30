#include<stdio.h>
#define N 10

int countSplit(int a[], int l, int r, int m)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int inversion = 0;
    int left[n1], right[n2];
    for(int i=0; i<n1; ++i)
    {
        left[i] = a[l+i];
    }
    for(int i=0; i<n2; ++i)
    {
        right[i] = a[m+i+1];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(left[i] > right[j])
        {
            inversion+=(m-i-l+1);
            // printf("split inversions: %d m=%d i=%d", inversion, m, i);
            a[k++] = right[j++];
        }
        else
        {
            a[k++] = left[i++];
        }
    }
    while(i<n1)
    {
        a[k++] = left[i++];
    }
    while(j<n2)
    {
        a[k++] = right[j++];
    }
    return inversion;
}
int countInversion(int a[], int l, int r)
{
    if(l == r)
        return 0;
    int m = (l+r)/2;
    int left = countInversion(a,l,m);
    int right = countInversion(a, m + 1, r);
    int split = countSplit(a,l,r,m);
    
    // printf("start: %d middle: %d end: %d\nleft: %d\nright: %d\nsplit: %d\n", l, m, r, left, right, split);
    return left+right+split;
}
int main()
{
    int a[] = {1,5,4,8,10,2,6,9,3,7};
    printf("The no. of inversions are: %d\n", countInversion(a, 0, N-1));
}