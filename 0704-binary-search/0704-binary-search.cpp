class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low =0; 
        int high = size(nums)-1;
        while( low<= high){
            int mid = (high + low)/2;
            if( nums[mid] == target){
                return mid;
            }
            else if( target < nums[mid]){
                high = mid-1;
                mid = (high + low)/2;
                }

            else if(target> nums[mid]){
                low= mid+1;
                mid = (high + low)/2;
            }
        }
        
        return -1;
    }
};