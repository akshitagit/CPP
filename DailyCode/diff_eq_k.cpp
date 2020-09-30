/* Problem statement - Given an array, ‘A’ of sorted integers and another non-negative integer k, find if there exist 2 indices i and j such that

    A[i] - A[j] = k
    i!= j

Required Time Complexity: O(n) */

/* Brief idea and algorithm (Using sliding window technique and no extra array required) */
 /*
   
    0. Since it is sorted, difference between any two elements (say A[i] and A[j])= sum of the differences of all the adjacent
       elements between them (i.e. between A[i] and A[j]).
    1. Maintain a start and end variable denoting the start and end of the window. Initialise both to 0.
    2. Now we will iterate through the array and continue expanding our window (i.e increment the end variable) 
       and keep on finding the sum of difference between the adjacent elements.
    3. Whenever the difference exceeds k, we will keep on incrementing start variable i.e. shift the starting of the window
    4. If any point the difference equals k make flag equals 1.
    5. Check the value of flag outside the loop. If it is 0 means no such element exists.
    5. The start and end variable traverse the whole array maximum once. Thus complexity = O(n)
*/

/* Code */
#include <iostream>
using namespace std;

int main()
{
    int n; //total number of elements in the array
    cin>>n;
    int A[n],i,k;
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    } 
    cin>>k;
   int diff = 0,st=0,end=0,flag=0; 
    while(end<n-1)
    {
      end++;
        diff+=A[end]-A[end-1]; //diff holds current difference between A[st] and A[end] 
        if(diff>k)
        {
            
            while(st<end && diff>k) 
            {
                diff=diff-(A[st+1]-A[st]); /* A[st] will be dropped from our window thus its difference
                                              with its adjacent element A[st+1] is subtracted from diff */
                st++; //shifting the start of the window 
            }
            
        }
        if(st!=end && diff==k) //check if diff equals k
        {
          flag = 1;
          break;
        }
        
    }
    if(flag)
        cout<<"Two elements with difference k = "<< k << " is present";
    else
        cout<<"No two elements with difference k = "<< k << " is present ";
}
//Time Complexity = O(n)
//Space Complexity = O(1)  No extra space required