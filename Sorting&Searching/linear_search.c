/* 

Algorithm:

Step 1: Input the size of the array

Step 2: Input the elements of the array

Step 3: Input the key element to be searched for

Step 4: Run a loop for all elemnts in the array

Step 5: Compare each element of array with the key element

Step 6: If the element is found , display it

Step 7: If the element is not found , display error message

Step 8: Stop

 */


#include<stdio.h>
int main(){
    int key,arr[50],n,i,flag=0;
    
    printf("Enter the number of elements:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        }    
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    
    for(i=0;i<n;i++){	 	  	 	   	      	     	      	 	
        
        if(key==arr[i]){
            printf("The element %d is found at position %d",key,i+1);
            flag =1;            
        }
    }
    if(flag==0){
        printf("Element not found");
    }
    
    return 0;
}
