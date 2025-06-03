class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        int m= nums.size();
        k= k % m;
         /*
        for ( int j = 0 ; j < k ; j ++ ){
            int temp = nums[m-1];
            for ( int i = 1; i < nums.size(); i++){
            nums[m-i] = nums[m-i-1];
            }
            nums[0] = temp;
        }
        */
        if ( k < 1) return ;
        int temp[k];
        for (int i = m - k; i < m; i++)
        {
            temp[i - m + k] = nums[i];
        }
        for (int i = m - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }

    }
};