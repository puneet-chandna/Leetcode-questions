class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int makority= 0;
        int maxx =0;
        
        
        map<int,int>mpp;
        for ( int i= 0; i< nums.size(); i++){
            mpp[nums[i]]++;
        }
        for (auto it : mpp){
            if ( it.second > nums.size()/2) return it.first;
            
        }


        return -1;
    }
};