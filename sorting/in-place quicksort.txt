// in-place quicksort... also called  Lomuto Partitioning method.
// here the last element is taken as the pivot element 
// also, in the output, the array is printed after every successful partition 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void display(int n, int *a)
    {
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int partition(int p,int q,int n,int *a)
    {
    int x=a[q],temp;
    int i=p,j=p;
    while(j<q)
        {
        if(a[j]<x)
            {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
        j++;
    }
    temp=a[q];
    a[q]=a[i];
    a[i]=temp; 
    return i;
}
void quicksort(int p,int q, int n,int *a) {
   if(p>=q)
       return;
    else
        {
        int m;
        m=partition(p,q,n,a);
        display(n,a);
        quicksort(p,m-1,n,a);
        quicksort(m+1,q,n,a);
    }
}
int main(void) {
   int ar_size;
   scanf("%d", &ar_size);
   int ar[ar_size], i;
   for(i = 0; i < ar_size; i++) { 
      scanf("%d", &ar[i]); 
   }
  
   quicksort(0,ar_size-1,ar_size, ar);
   
   return 0;
}
