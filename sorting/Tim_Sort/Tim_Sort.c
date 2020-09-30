#include<stdio.h>  
const int run = 32;  
int minimum(int a, int b)  
{  
    if(a<b)  
    return a;   
    else   
    return b;   
}  
void insertionSort(int a[], int beg, int end)  
{  
    int temp, i, j;   
    for (i = beg + 1; i <= end; i++)  
    {  
        temp = a[i];  
        j = i - 1;  
        while (a[j] > temp && j >= beg)  
        {  
            a[j+1] = a[j];  
            j--;  
        }  
        a[j+1] = temp;  
    }  
}  
   
void merge(int a[], int left, int mid, int right)  
{  
    int len1 = mid - left + 1, len2 = right - mid;  
    int beg[len1], end[len2];  
    int i,j,k;  
    for (i = 0; i < len1; i++)  
        beg[i] = a[left + i];  
    for (i = 0; i < len2; i++)  
        end[i] = a[mid + 1 + i];  
   
    i = 0;  
    j = 0;  
    k = left;  
   
    while (i < len1 && j < len2)  
    {  
        if (beg[i] <= end[j])  
        {  
            a[k] = beg[i];  
            i++;  
        }  
        else  
        {  
            a[k] = end[j];  
            j++;  
        }  
        k++;  
    }  
    while (i < len1)  
    {  
        a[k] = beg[i];  
        k++;  
        i++;  
    }  
   
    while (j < len2)  
    {  
        a[k] = end[j];  
        k++;  
        j++;  
    }  
}  
void timSort(int a[], int n)  
{  
    int i,size,beg,mid,end;  
    for (i = 0; i < n; i+=run)  
        insertionSort(a, i, minimum((i+31), (n-1)));  
    for (size = run; size < n; size = 2*size)  
    {  
        for (beg = 0; beg < n; beg += 2*size)  
        {  
            mid = beg + size - 1;  
            end = minimum((beg + 2*size - 1), (n-1));  
   
            merge(a, beg, mid, end);  
        }  
    }  
}  
  
int main()  
{  
    int a[] = {12,1,20,2,3,123,54,332},i;  
    int n = sizeof(a)/sizeof(a[0]);  
    printf("Printing Array elements \n");  
    for (i = 0; i < n; i++)  
    printf("%d  ", a[i]);  
    printf("\n");  
    timSort(a, n);  
   
    printf("Printing sorted array elements \n");  
    for (i = 0; i < n; i++)  
        printf("%d  ", a[i]);  
    printf("\n");  
    return 0;  
}  