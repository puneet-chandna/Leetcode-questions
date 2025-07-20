struct Trie {
    unordered_map<string, shared_ptr<Trie>> ch;
    bool del = false;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        auto root = make_shared<Trie>();
        for (auto& p : paths) {
            auto node = root;
            for (auto& s : p) {
                if (!node->ch.count(s))
                    node->ch[s] = make_shared<Trie>();
                node = node->ch[s];
            }
        }

        unordered_map<string, vector<shared_ptr<Trie>>> mp;
        dfs(root, mp);

        for (auto& [_, vec] : mp)
            if (vec.size() > 1)
                for (auto& node : vec)
                    node->del = true;

        vector<vector<string>> ans;
        vector<string> cur;
        collect(root, cur, ans);
        return ans;
    }

private:
    string dfs(shared_ptr<Trie> node,
               unordered_map<string, vector<shared_ptr<Trie>>>& mp) {
        string sub = "(";
        vector<string> keys;
        for (auto& [s, c] : node->ch)
            keys.push_back(s);
        sort(keys.begin(), keys.end());
        for (auto& s : keys)
            sub += s + dfs(node->ch[s], mp);
        sub += ")";
        if (sub != "()")
            mp[sub].push_back(node);
        return sub;
    }

    void collect(shared_ptr<Trie> node, vector<string>& cur,
                 vector<vector<string>>& ans) {
        for (auto& [s, c] : node->ch) {
            if (c->del) continue;
            cur.push_back(s);
            collect(c, cur, ans);
            cur.pop_back();
        }
        if (!cur.empty())
            ans.push_back(cur); 
    }
};