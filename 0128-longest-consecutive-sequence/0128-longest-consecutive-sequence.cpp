class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest=1;
        int count = 0;
        int last = INT_MIN;
        if(nums.size()== 0 ) return 0;
        for(int i=0;i< nums.size();i++){
            
            
            if(nums[i] -1 == last) {
                count++;
                 last = nums[i];}
            
            else if(nums[i] != last) {
                count=1; 
                last = nums[i];}
            longest= max(count, longest);
        }
        return longest;
    }
};