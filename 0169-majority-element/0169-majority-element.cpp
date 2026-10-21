class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max= 0;
        int high= 0;

         for ( int i =0; i < nums.size(); i++){
            if( high==0) max = nums[i];
            if (nums[i] == max) high ++;
            else high --;
         }
         return max;
    }
};