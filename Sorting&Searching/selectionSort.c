#include<stdio.h>
#include<stdlib.h>

void selection(int *a,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		int small=a[i];
		int pos=i;
		
		for(j=i+1;j<n;j++)
		if(small>a[j])
		{
			small=a[j];
			pos=j;
		}
		
		a[pos]=a[i];
		a[i]=small;
	}
}

void main()
{
	int *a,i,n;
	printf("Enter n : ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	selection(a,n);
	
	printf("Sorted Array : ");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
