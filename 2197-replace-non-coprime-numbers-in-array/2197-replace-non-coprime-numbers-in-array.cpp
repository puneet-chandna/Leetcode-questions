class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
       vector<int> st;
        st.reserve(nums.size());
        
        for (int num : nums) {
           
            while (!st.empty()) {
                int top = st.back();
                int g = gcd(top, num);
                if (g == 1) break;  
                long long l = (long long)top / g * num;
                num = (int)l;
                st.pop_back();
            }
            st.push_back(num);
        }
        return st;
    }
    
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
     
    }
};