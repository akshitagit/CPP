//Function to search for a element in rotated sorted array

int search(vector<int>& nums, int target) {
        
        int left=0,right =nums.size()-1;
        int mid;
        
        while(left<=right){
            mid = left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[left]<=nums[mid]){
                if(target>=nums[left] && target<nums[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                if(target<=nums[right] && target>nums[mid]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            
        }
        return -1;
        
        
    }
