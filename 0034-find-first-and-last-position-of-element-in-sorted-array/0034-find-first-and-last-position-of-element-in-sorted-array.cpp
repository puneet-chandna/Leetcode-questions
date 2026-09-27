class Solution {
public:
    
    int firsto(vector<int> &nums, int target){
        int low= 0;
        int high = nums.size() -1;
        int firsto= -1;
         while ( low<= high){
            int mid = (low + high)/2;
            if( target== nums[mid]) firsto = mid, high= mid-1;
            else if(target < nums[mid]) high = mid-1;
            else low = mid +1;

         }
         return firsto;
    }
    int lasto(vector<int> &nums, int target){
        int low= 0;
        int high = nums.size() -1;
        int lasto = -1;
         while ( low<= high){
            int mid = (low + high)/2;
            if( target== nums[mid]) lasto = mid, low= mid+1;
            else if(target < nums[mid]) high = mid-1;
            else low = mid +1;

         }
         return lasto;
    }
    vector<int> searchRange(vector<int> &nums, int target) {
        
        
        int firsti= firsto(nums, target);
        if (firsti == -1) return {-1, -1};
        int lasti = lasto(nums, target);
         
        return {firsti,lasti};
    }
};