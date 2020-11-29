#include <stdio.h>
int main()
{
    int arr[50], i, j, k, temp, n, count;
    printf("Enter the no of elements: ");       //input number of elements
    scanf("%d", &n);
    printf("Enter the elements:\n");            //imput elements
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n - 1; i++)
    {
        count = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        if (count == 0)
            break;
        printf("\nPass %d: ", i);
        for (k = 0; k < n; k++)
            printf("%d ", arr[k]);
    }
    printf("\nSorted list is: ");              //printing sorted list
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
