#include <iostream>
#include <vector>
using namespace std;
//solved using kadane's algorithm
// we start with initiating current_sum to the first element
// now we will decide if we wanna add the next element to our window
//we will start a new window from current element
// if current_sum+current element> current element, we will add current element to our window
//else we start a new window from current element
//in the process we will keep updating max_sum
int finaMaxSubArraySum(vector<int> &nums)
{
    int current_sum=nums[0];
    int max_sum=current_sum;
    
    for(int i=0; i<nums.size(); i++)
    {
        current_sum=max(current_sum+nums[i], nums[i]);
        max_sum=max(max_sum,current_sum);
    }
    
    return max_sum;
    
}


int main()
{
   vector<int> nums;
   int n;
   cout << "Enter the size of the array: ";
   cin>>n;
   nums.resize(n);
   for(int i=0; i<n; i++)
   {
   	cin>> nums[i];
   }
   
   int max_sum=finaMaxSubArraySum(nums);
   cout << max_sum<<endl;

}
