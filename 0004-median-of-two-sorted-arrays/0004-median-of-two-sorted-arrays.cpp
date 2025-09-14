class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size(), n = nums2.size();
        int total = m + n;
       
        int leftPos = (total + 1) / 2;
        int rightPos = (total + 2) / 2;
        double leftVal = findKth(nums1, 0, nums2, 0, leftPos);
        double rightVal = findKth(nums1, 0, nums2, 0, rightPos);
        return (leftVal + rightVal) / 2.0;
    }


    int findKth(const vector<int>& A, int i, const vector<int>& B, int j, int k) {
        int m = A.size(), n = B.size();
        if (i >= m) return B[j + k - 1];
        if (j >= n) return A[i + k - 1];
        if (k == 1) return min(A[i], B[j]);
        int half = k / 2;
        int Ai = (i + half - 1 < m) ? A[i + half - 1] : INT_MAX;
        int Bj = (j + half - 1 < n) ? B[j + half - 1] : INT_MAX;
        if (Ai < Bj) {
      
            return findKth(A, i + half, B, j, k - half);
        } else {
        
            return findKth(A, i, B, j + half, k - half);
        } 
    }
};