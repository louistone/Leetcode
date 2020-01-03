//Author: Tong Xu
//Date: 1/2/2020

// 2 pointer + greedy

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty()) return 0;
        int l = 0, r = height.size()-1, res = 0;
        while(l < r) {
            int h = min(height[l], height[r]);
            res = max(res, h*(r-l));
            height[l] <= height[r] ? l++ : r--; // greedy method
        }

        return res;
    }
};
