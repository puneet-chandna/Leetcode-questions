class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long current_sum = 0;
        for (int num : nums) {
            current_sum += num;
        }

     
        int remainder = static_cast<int>(current_sum % k);

       
        return remainder;
    }
};