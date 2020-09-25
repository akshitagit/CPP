#include <stdio.h>
void quicksort_method (int [], int, int);
int main()
{
int element_list[50],count, counter;
scanf("%d", &count);
for (counter = 0; counter < count; counter++)
{
scanf("%d", &element_list[counter]);
}
quicksort_method(element_list, 0, count - 1);
for (counter = 0; counter < count; counter++)
{
printf("%d ", element_list[counter]);
}
printf("\n");
return 0;
}
void quicksort_method(int element_list[], int low, int high)
{
int pivot, value1, value2, temp;
if (low < high)
{
pivot = low;
value1 = low;
value2 = high;
while (value1 < value2)
{
while (element_list[value1] <= element_list[pivot] && value1 <= high)
{
value1++;
}
while (element_list[value2] > element_list[pivot] && value2 >= low)
{
value2--;
}
if (value1 < value2)
{
temp = element_list[value1];
element_list[value1] = element_list[value2];
element_list[value2] = temp;
}
}
temp = element_list[value2];
element_list[value2] = element_list[pivot];
element_list[pivot] = temp;
quicksort_method(element_list, low, value2 - 1);
quicksort_method(element_list, value2 + 1, high);
}
}
