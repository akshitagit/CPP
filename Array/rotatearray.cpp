//Rotate an array to the right by k positions using Juggling Algorithm

/*If we shift elements one by one, it will be difficult to keep track of all the elements without using extra space.
Instead we divide the array into sets/cycles and shift every element in a set k places to the right.
Then we move to the next set and repeat the process.

Here, the no. of sets will be the gcd of n and k, where n is the size of the array */

class Solution {
public:
    int calcGcd(int a, int b) {
        if (b == 0) return a;
        return calcGcd(b, a % b);
    }

    void rotate(vector<int>& nums, int k) {
        /*  Example:
                  n = 7, k = 3, gcd = 1
            
Before Rotation:  index = 0 1 2 3 4 5 6
                  array =[1,2,3,4,5,6,7]
            
After Rotation:   index = 0 1 2 3 4 5 6
                  array =[5,6,7,1,2,3,4]
    
            i = 0            
            temp = 7
            currIndex = 2            (n - i - 1)            
            prevIndex = 6            (currIndex - d)
        */
        
        const int n = nums.size();
        k = k % n;
        int gcd = calcGcd(n, k);
        
        for (int i = 0; i < gcd; i++) {
            int currIndex = n - i - 1;
            int temp = nums[currIndex];

            while (true) {
                int prevIndex = currIndex - k;
                if (prevIndex < 0) prevIndex += n;
                if (prevIndex == n - i - 1) break;
                
                nums[currIndex] = nums[prevIndex];
                currIndex = prevIndex;
            }
            nums[currIndex] = temp;
        }
    }
};
