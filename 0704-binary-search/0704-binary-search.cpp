class Solution {
public:
    int ullu(vector<int>& nums, int low, int high, int target){
        if( low> high) return -1;
        int mid= (low+high)/2;
        if(nums[mid]== target)return  mid;
        else if(target>nums[mid]) return ullu(nums,mid+1,high,target);
        else if(target<nums[mid])return ullu(nums,low ,mid-1,target);
        return 0;
    }

    int search(vector<int>& nums, int target) {
        
        int low =0; 
        int high = size(nums)-1;
        
        
        return ullu(nums,low,high,target);
    }
};