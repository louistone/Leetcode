// Author: Tong Xu
// Date: 01/06/2020
// pure combination without permutation
// [2, 4] and [4, 2] are treated the same, in the return result, only [2, 4] is included

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dfs(n, k, cur, 1);
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(int n, int k, vector<int>& cur, int pos) {
        if(k == 0) {
            res.push_back(cur);
            return;
        }

        for(int i = pos; i <= n; i++) {
            cur.push_back(i);
            dfs(n, k-1, cur, i+1);
            cur.pop_back();
        }
    }
};
