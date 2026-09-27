class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size()-1;
        while (low<= high){
            int mid = (low+high)/2;
            if(nums[mid] == k) return true;
            if(nums[low] == nums[mid] && nums[mid]==nums[high]) {
                low ++, high--; 
                continue;
                }
            //left sorted
            else if(nums[low]<= nums[mid] )
            {
             
                if( nums[mid]> k && nums[low]<=k) high = mid-1;
                else low = mid+1;
            }
            //right sorted
            else if (nums[high]>= nums[mid] ){
                
                if(nums[mid]<k && nums[high]>=k) low= mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};