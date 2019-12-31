//Author: Tong Xu
//Date: 12/30/2019
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long sum = 0;
        int org = x;

        while(x) {
          sum = sum*10 + x%10;
          x /= 10;
        }

        return sum == org;
    }
};
