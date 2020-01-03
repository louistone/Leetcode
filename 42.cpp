//Author: Tong Xu
//Date: 1/2/2020

// 42: Trapping Rain Water this problem 11: Container with Most Water

class Solution {
public:
  int trap(vector<int>& height) {
    if(height.empty()) return 0;
    int l = 0, r = height.size()-1, maxLeft = 0, maxRight = 0, res = 0, h;

    while(l < r) {
      maxLeft = max(maxLeft, height[l]);
      maxRight = max(maxRight, height[r]);
      h = min(maxLeft, maxRight);
      if(maxLeft <= maxRight) {
          res += h >= height[l] ? h - height[l] : 0;
          l++;
      }
      else {
          res +=  h >= height[r] ? h - height[r] : 0;
          r--;
      }
    }

    return res;
  }
};
