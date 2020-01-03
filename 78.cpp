//Author: Tong Xu
//Date: 1/2/2020
// dfs(nums, cur, k, pos) ==> dfs(nums, cur, k, i+1)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        vector<int> cur;
        for(int k = 0; k <= n; k++) {
            dfs(nums, cur, k, 0);
        }

        return res;
    }

private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& cur, int k, int pos) {
        if(k == 0) {
            res.push_back(cur);
            return;
        }

        for(int i = pos; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(nums, cur, k-1, i+1);
            cur.pop_back();
        }
    }
};
