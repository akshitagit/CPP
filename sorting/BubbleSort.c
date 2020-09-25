#include<stdio.h>
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
int bubble_sort(int arr[],int N){
	int i,j;
	int count=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				count++;
			}
		}
	}
	return count;
}
int main(){
	int N;
	int i;
	scanf("%d",&N);
	int arr[N];
	for(i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	int swaps;
	swaps=bubble_sort(arr,N);
	printf("%d",swaps);
}
