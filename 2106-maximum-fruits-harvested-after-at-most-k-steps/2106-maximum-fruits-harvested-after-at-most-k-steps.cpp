class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxRight = max(startPos, fruits.back()[0]);
    vector<int> amt(maxRight+1), prefix(maxRight+2);
    for (auto& f: fruits) amt[f[0]] = f[1];
    partial_sum(amt.begin(), amt.end(), prefix.begin()+1);

    auto collect = [&](int leftSteps, int rightSteps) {
      int L = max(0, startPos - leftSteps);
      int R = min(maxRight, startPos + rightSteps);
      return prefix[R+1] - prefix[L];
    };

    int ans = 0, maxR = min(maxRight - startPos, k);
    for (int rs = 0; rs <= maxR; ++rs)
      ans = max(ans, collect(max(0, k - rs*2), rs));

    int maxL = min(startPos, k);
    for (int ls = 0; ls <= maxL; ++ls)
      ans = max(ans, collect(ls, max(0, k - ls*2)));

    return ans;
    }
};