#include<stdio.h>

int main()
{
    int n, a,b, hcf=1, temp;
    
    printf("A program to find out the HCF of two numbers\n");
    printf("Enter the number of iterations: ");
    scanf("%d",&n);
    for(int i = 0; i<n;i++)
    {
        printf("Enter the numbers: ");
        scanf("%d%d",&a,&b);

            while (b != 0)
            {
                temp = b;
                b = a % b;
                a = temp;
            }
                hcf = a;
                printf("\nHCF = %d\n",hcf);
            }
}
