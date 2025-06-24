class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();
        
        int start = 0; 

        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int left_boundary = std::max(start, i - k);
                int right_boundary = std::min(n - 1, i + k);

                for (int j = left_boundary; j <= right_boundary; ++j) {
                    result.push_back(j);
                }

                start = right_boundary + 1;
            }
        }

        return result;
    }
};