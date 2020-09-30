#include <stdio.h>
int main()
{
int array[100], n, c, d, position, swap;

// taking array size as input 
printf("\n------------------------------------------------\n");
printf("Enter number of elements\n");
scanf("%d", &n);
printf("------------------------------------------------\n");

// entering values inside array
printf("\n------------------------------------------------\n");
printf("Enter %d integers\n", n);
for (c = 0; c < n; c++)
scanf("%d", &array[c]);
printf("\n------------------------------------------------\n");



// Selection sort algorithm
for (c = 0; c < (n - 1); c++)
{
    position = c;
    for (d = c + 1; d < n; d++)
    {
        if (array[position] > array[d])
        position = d;
    }
    if (position != c)
    {
        swap = array[c];
        array[c] = array[position];
        array[position] = swap;
    }
}
// end of algorithm


printf("\n------------------------------------------------\n");
printf("\n\t..........................\n\t applying Selection Sort\n\t..........................\n");
printf("\n------------------------------------------------\n");


// printing sorted array
printf("Sorted list in ascending order:\n");
for (c = 0; c < n; c++)
printf("%d\n", array[c]);

return 0;
}
// main end
