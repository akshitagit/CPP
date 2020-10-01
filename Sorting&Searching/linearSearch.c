#include<stdio.h>

void linearSearch(int *, int, int);

int fqncy = 0;

int main()
{
  int size;
  printf("Linear Search Program\n");
  printf("Enter the size of array:\n");
  scanf("%d", &size);
  int arr[size];
  int i, data;
  for (i = 0; i < size; i++ )
  {
    printf("[%d]: ", i);
    scanf("%d", &arr[i]);
  }
  printf("Enter the data to search:\n" );
  scanf("%d", &data);



  linearSearch(arr, size, data);

  /*int index;
  index = linearSearch(arr, size, data);

  if (index == -1)
    printf("The data is not present in the array!\n");
  else
    printf("It's position is %d.\n", index + 1);*/

  printf("The loop run for %d time/times.", fqncy);

  return 0;
}

void linearSearch(int *ar, int size, int data)
{
  int i, found = 0;
  for(i = 0; i < size; i++)
  {
    fqncy += 1;
    printf("Comparing with element at index %d \n", i);
    if(ar[i] == data)
    {
      printf("Yes! I found it, the element is at index %d.\n", i);
      found = 1;
    //break;
    //  return i;
    }
    else
      printf("Sad! Element is not found at index %d\n", i);
    if(found == 1)
    {
      printf("Hurray ! Exiting the loop now.\n");
      break;
    }
    printf("Going for next comparision...\n");
  }

//  return -1;
}
