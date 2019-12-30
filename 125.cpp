// Date: 12/30/2019
// Author: Tong Xu

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int l = 0, r = s.size()-1;
        while(l <= r) {
            if(!isalnum(s[l])) {
                l++;
                continue;
            }
            if(!isalnum(s[r])) {
                r--;
                continue;
            }

            if(toupper(s[l]) != toupper(s[r])) return false;
            l++, r--;
        }
        return true;
    }
};
