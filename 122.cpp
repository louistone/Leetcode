// Author: Tong Xu
// Date: 12/30/2019

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(prices.empty()) return 0;
      int maxProfit = 0, n = prices.size();
      for(int  i = 0; i < n-1; i++) {
        maxProfit += prices[i+1] > prices[i] ? prices[i+1]-prices[i] : 0;
      }
      return maxProfit;
    }
};
