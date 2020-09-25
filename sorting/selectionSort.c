#include<stdio.h>
#include<malloc.h>

void selectionSort(int *arr, int n) {
    int i, j, pos_min, temp;
    for(i=0;i<n-1;i++) {
        pos_min = i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[pos_min])
                pos_min = j;
        temp = arr[i];
        arr[i] = arr[pos_min];
        arr[pos_min] = temp;
    }
}

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, *arr, i;
    printf("Enter size of an array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n*sizeof(int));

    printf("Enter elements of array: ");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
