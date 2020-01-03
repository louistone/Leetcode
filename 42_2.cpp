// Author: Tong Xu
// Date: 1/2/2020
// Use 2 array to store left max and right max

class Solution {
public:
  int trap(vector<int>& height) {
    if(height.empty()) return 0;
    vector<int> maxLeft;
    vector<int> maxRight;
    int res = 0, h;
    maxLeft.push_back(height[0]);
    maxRight.push_back(height.back());
    for(int i = 1; i < height.size(); i++)
      maxLeft.push_back(max(maxLeft.back(), height[i]));
    for(int i = height.size() - 2; i >= 0; i--)
      maxRight.insert(maxRight.begin(), max(maxRight[0], height[i]));
    for(int i = 0; i < height.size(); i++) {
      h = min(maxLeft[i], maxRight[i]);
      res += h >= height[i] ? h - height[i] : 0;
    }
    return res;
  }
};
