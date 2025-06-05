class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx = INT_MIN;
        int sum = 0;
        int i=0;
        if (nums.size() == 1)return nums[0];
        for( i=0 ; i<nums.size();i++){
            sum = sum +nums[i];
            maxx = max(sum, maxx);
            if(sum<0){ sum = 0;}
            
        }
        if ( sum <0){
            int min = INT_MIN;
            for(int j=0 ; j<nums.size();j++){
                if( nums[j] > min) min = nums[j];
            }
            return min;
        }
        return maxx;
    }
};