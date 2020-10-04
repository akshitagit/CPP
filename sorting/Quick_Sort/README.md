# Quick Sort

Quick Sort is a divide and conquer algorithm that creates two empty arrays to hold elements less than the pivot value and elements greater than the pivot value, and then recursively sort the sub arrays. There are two basic operations in the algorithm, swapping items in place and partitioning a section of the array.

## Algorithm

1. Find a “pivot” item in the array. This item is the basis for comparison for a single round.
2. Start a pointer (the left pointer) at the first item in the array.
3. Start a pointer (the right pointer) at the last item in the array.
4. While the value at the left pointer in the array is less than the pivot value, move the left pointer to the right (add 1). Continue until the value at the left pointer is greater than or equal to the pivot value.
5. While the value at the right pointer in the array is greater than the pivot value, move the right pointer to the left (subtract 1). Continue until the value at the right pointer is less than or equal to the pivot value.
6. If the left pointer is less than or equal to the right pointer, then swap the values at these locations in the array.
7. Move the left pointer to the right by one and the right pointer to the left by one.
8. If the left pointer and right pointer don’t meet, go to step 1.

## Pseudocode

The pseudocode for Quick Sort is as follows:

```
quicksort(A,p,r) {
    if (p < r) {
       q <- Partition(A,p,r)
       Quicksort(A,p,q)
       Quicksort(A,q+1,r)
    }
}

partition(A,p,r)
    x <- A[p]
    i <- p-1
    j <- r+1
    while (true) {
        repeat
            j <- j-1
        until (A[j] <= x)
        repeat
            i <- i+1
        until (A[i] >= x)
        if (i A[j]
        else 
            return(j)
    }
}
```

## Example

Below given is an array, which needs to be sorted. We will use the Quick Sort Algorithm to sort this array:

![Quick Sort](https://cdn-images-1.medium.com/max/800/1*DtH6fEdBhoUGnjBWudJ8pA.png)


## Quick Sort Analysis:

**1. Divide and Conquer Algorithm**

**2. Recursive Algorithm**

**3. In-place** (Although it takes space complexity of O(logn) but it's very small so it approximates to O(1).

**4. Unstable** (Equal elements may/may not come in order as they were initially)

**5. Time Complexity:**

    Worst: O(n^2)   
    
    Average: Theta(nlogn)
    
    Best: Omega(nlogn)
    
    
**NOTE:** Worst case can almost always be avoided using concept of Randomized Quick Sort.

# Randomized Quick Sort
Randomized Quick Sort is same as Quick Sort but the fact that changes is the selection of pivot.
In normal Quick Sort we either choose last element or first element of array as pivot, but in Randomized Quick Sort
we choose any random element as a pivot.

## Advantage of Randomized Quick Sort:
1. It increases the probability that the array will be divided in half.
2. Since the chances of selecting biggest or smallest element is low the probabily of getting worst case 
performance also reduces.
3. Worst case time complexity is O(nlogn).
