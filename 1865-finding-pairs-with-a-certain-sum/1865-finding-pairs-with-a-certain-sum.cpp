class FindSumPairs {
public:
    vector<long long> nums1;
    vector<long long> nums2;
    unordered_map<long long, int> freq2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1.assign(nums1.begin(), nums1.end());
        this->nums2.assign(nums2.begin(), nums2.end());
        for (long long v : this->nums2)
            freq2[v]++;
    }

    void add(int index, int val) {
        long long old = nums2[index];
        freq2[old]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        long long ans = 0;
        for (long long x : nums1) {
            long long need = (long long)tot - x;
            if (freq2.count(need))
                ans += freq2[need];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */