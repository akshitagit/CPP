#include <stdio.h> 

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

int knapSack_algo (int W, int array_b[], int array_a[], int n) 
{ 

    if (n == 0 || W == 0) 
        return 0; 

    if (array_b[n - 1] > W) 
        return knapSack_algo (W, array_b, array_a, n - 1); 
  
    else
        return max (array_a[n - 1] + knapSack_algo (W - array_b[n - 1], array_b, array_a, n - 1), 
            knapSack_algo (W, array_b, array_a, n - 1)); 
} 

int main() 
{ 
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int num_a;
    int array_a[10], array_b[10];
    printf("Enter the size of the array : ");
    scanf("%d", &num_a);
    
    printf("Enter the elements in the array 1 -> \n");
    for ( int i=1; i <= num_a; i++)
    {
        printf("Enter the %d value = ",i);
        scanf("%d", &array_a[i]);
    }
    
    printf("Enter the elements in the array 2 -> \n");
    for ( int j=1; j <= num_a; j++)
    {
        printf("Enter the %d value = ",j);
        scanf("%d", &array_b[j]);
    }
    
    int n = sizeof(array_a) / sizeof(array_a[0]); 
    printf("%d", knapSack_algo (W, array_b, array_a, n)); 
    return 0; 
} 
