//Author: Tong Xu
//Date: 01/03/2020
//Solution: One stack

class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> numStack;
        numStack.push(-1);
        int maxL = 0;

        for(int i = 0; i < s.size(); i++) {
            int t = numStack.top();
            if(t != -1 && s[i] == ')' && s[t] == '(') {
                numStack.pop();
                maxL = max(maxL, i-numStack.top());
            }
            else
                numStack.push(i);
        }

        return maxL;
    }
};
