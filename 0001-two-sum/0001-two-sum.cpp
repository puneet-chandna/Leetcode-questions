class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mapp;
        vector<int> sum;
        for(int i  = 0 ; i<nums.size(); i++){
            
            int a = nums[i];
            int diff = target - a;
            if(mapp.find(diff)!= mapp.end()){
                return {mapp[diff], i};
                
            }
            mapp[a] = i;
        }
        return {-1,-1};
    }
};