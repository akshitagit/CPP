#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Function: binarySearch
 * ----------------------
 * checks RECURSIVELY for the target value in array and prints the index if found +
 * number of comparisons made
 * 
 * array[]: array with sorted random numbers
 * start: starting position of the subarray
 * end: end position of the subarray
 * target_value: value that needs to be searched in the arary.
 * count: counter for number of comparisons made
 * 
 * returns: none
*/
int binarySearch(int array[], int start, int end, int target_value, int count){
    // post incerement the counter

    if( end >= start ){
        count++;
        int mid = (start + end)/2 ;

        // Check if the target_value is same as middle value
        if(array[mid] == target_value){
            
            printf("Element found at index: %d \n", mid);
            printf("Number of Comparisons done: %d \n", count-1);
            return 0;
        }

        // If target_value is smaller than mid, then 
        // it can only be present in left subarray 
        else if(target_value < array[mid]){
            
            return binarySearch(array, start, mid-1, target_value, count) ;        
        } 
        
        // Else the element can only be present 
        // in right subarray 
        else{
            
            return binarySearch(array, mid+1, end, target_value, count);
        } 
    
    }

    else{
        // If no matching target_value is found
        printf("Oops! No such element found in the array!\nTotal comparisons made: %d\n", count-1);
        return 0; 
    }
}

int main(){

    // input size of array (integer)
    int sizeOfArray;
    printf("Enter the Size of Array! \n");
    scanf("%d", &sizeOfArray);

    // Initialize seed for Psuedo random number generator
    srand(time(0));

    // add random numbers to the array using rand() function
    int index, array[sizeOfArray];
    array[0] = rand() % 100;

    for ( index = 1 ; index < sizeOfArray; index++ ){
        array[index] = array[index-1] + rand() % 100;
    }

    // print the arary
    for( index = 0; index < sizeOfArray; index++ ){
        printf("%d\t", array[index]);
    }

    printf("\n*****************************\n");

    //input the number to be searched
    printf("Your randomly sorted array is ready!Enter a number below to search. \n");
    int target;
    scanf("%d", &target);

    int comparisonCount  = 0;
    // binary search
    binarySearch(array, 0, sizeOfArray-1, target, comparisonCount);
    
    return 0;
}