class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
         vector<int> A1, A2, B1, B2;
        separate(nums1, A1, A2);
        separate(nums2, B1, B2);

        long long negCount = (long long)A1.size() * B2.size() + (long long)A2.size() * B1.size();
        int sign = 1;
        if (k > negCount) {
            k -= negCount;
        } else {
            k = negCount - k + 1;
            sign = -1;
            swap(B1, B2);
        }

        long long l = 0, r = 10000000000LL;
        while (l < r) {
            long long m = l + (r - l) / 2;
            if (countLE(A1, B1, m) + countLE(A2, B2, m) >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return sign * l;
    }

private:
    void separate(const vector<int>& arr, vector<int>& negs, vector<int>& poss) {
        for (int x : arr) {
            if (x < 0) negs.push_back(-x);
            else poss.push_back(x);
        }
        reverse(negs.begin(), negs.end());
    }

    long long countLE(const vector<int>& A, const vector<int>& B, long long limit) {
        long long cnt = 0;
        int j = (int)B.size() - 1;
        for (long long a : A) {
            while (j >= 0 && a * B[j] > limit) j--;
            cnt += (j + 1);
        }
        return cnt;
    }
};