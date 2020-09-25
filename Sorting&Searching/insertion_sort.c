#include <stdio.h>
int main()
{
    int arr[50], i, j, k, p, n;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        for (j = i - 1; j >= 0 && k < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = k;
        printf("\nPass %d: ", i);
        for (p = 0; p < n; p++)
            printf("%d ", arr[p]);
    }
    printf("\nSorted list is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}