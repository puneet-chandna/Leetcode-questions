class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int partitions = 0;
        if (nums.empty()) {
            return 0;
        }

        int current_partition_min = nums[0];
        partitions = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - current_partition_min > k) {
                partitions++;
                current_partition_min = nums[i];
            }
        }
        return partitions;
    }
};