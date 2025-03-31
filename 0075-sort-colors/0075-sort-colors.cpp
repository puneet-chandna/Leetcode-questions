class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count1=0;
        int count2= 0;
        int count3=nums.size()-1;
        
        while(count2 <=count3){
            if(nums[count2]==0){
               swap(nums[count1],nums[count2]); 
               count1++;
               count2++;
            } 
            else if(nums[count2]==1){
                count2++;
            }
            
            else if( nums[count2] ==2){
                swap(nums[count2],nums[count3]); 
                
                count3--;
            }

        }
                
          

    }
};