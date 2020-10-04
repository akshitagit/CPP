#include<stdio.h>
#include<conio.h>
void main()
{
int i,j,x,y,a[20];
printf("enter the places to be inserted");
scanf("%d",&y);
printf("enter the numbers:);
for (i = 0; i < y; ++i)
            scanf("%d", &a[i]);
 
        for (i = 0; i < y; ++i) 
        {
 
            for (j = i + 1; j < y; ++j)
            {
 
                if (a[i] > a[j]) 
                {
 
                    x =  a[i];
                   a[i] = a[j];
                    ar[j] = x;
 
                }
 
            }
 
        }
        printf("Ascending order:");
        (i = 0; i < y; ++i)
         {scanf("%d\n",a[i]);}
         }
