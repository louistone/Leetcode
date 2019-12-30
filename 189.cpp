
// Author: Tong Xu
// Date: 12/30/2019
// Test


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return;
        int n = nums.size();
        k = k % n;
        for(int i = 1; i <= k; i++) {
        	nums.insert(nums.begin(), nums.back());
        	nums.pop_back();
        }
    }
};
