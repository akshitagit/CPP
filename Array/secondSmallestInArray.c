// Second smallest

#include <stdio.h>
void sort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n-1; i++){
            for (j = 0; j < n-i-1; j++){
                if (arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    }
                }
            }
        }

int main(){
    
    int n,i;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nInput the array elements : ");
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr, n);
    printf("\nThe second smallest element is %d \n",arr[1]);
    return 0;
}