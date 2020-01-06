// Author: Tong Xu
// Date: 01/06/2020
// Permutation: A(n, k);

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        unordered_set<int> visited;
        dfs(n, k, cur, 1, visited);
        cout << res.size() << endl;
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(int n, int k, vector<int>& cur, int pos, unordered_set<int>& visited) {
        if(k == 0) {
            res.push_back(cur);
            return;
        }

        for(int i = pos; i <= n; i++) {
            if(visited.count(i)) continue;
            cur.push_back(i);
            visited.insert(i);
            dfs(n, k-1, cur, pos, visited);
            visited.erase(i);
            cur.pop_back();
        }
    }
};
