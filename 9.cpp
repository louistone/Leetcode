// Author: Tong Xu
// Date: 2019/12/30

class Solution {
private:
  vector<int> convertNum(int x) {
    vector<int> res;
    while(x) {
      res.push_back(x%10);
      x /= 10;
    }
    return res;
  }

  bool checkVec(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    while(l <= r) {
      if(nums[l] != nums[r]) return false;
      l++, r--;
    }
    return true;
  }

public:
    bool isPalindrome(int x) {
      if(x < 0) return false;
      if(x == 0) return true;
      vector<int> numVec = convertNum(x);
      return checkVec(numVec);
    }
};
