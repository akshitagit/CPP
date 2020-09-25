/* 
contributions 
lonebots ( jishnu )
*/
//including headerfiles
#include<stdio.h>
#include<stdlib.h>

//main program
int main()
{
int array[100], num, i, j, swap; 
printf("Enter number of elements\n");
scanf("%d", &num); 
printf("Enter %d Numbers:n", n); 
for(i = 0; i < num; i++)
scanf("%d", &array[i]); 
for(i = 0 ; i < num - 1; i++)
{
for(j = 0 ; j < num-i-1; j++)
{
if(array[j] > array[j+1]) 
{
swap=array[j];
array[j]=array[j+1];
array[j+1]=swap;
}
}
} 
printf("Sorted Array:n"); 
for(i = 0; i < num; i++)
printf("%dn", array[i]);
return 0;
}
