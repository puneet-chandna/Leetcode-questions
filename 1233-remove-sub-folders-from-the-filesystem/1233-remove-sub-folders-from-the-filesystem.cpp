class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        string prev;
        for (auto& f : folder) {
            if (!prev.empty() && f.rfind(prev, 0) == 0 && f[prev.size()] == '/')
                continue;
            ans.push_back(f);
            prev = f;
        }
        return ans;
    }
};