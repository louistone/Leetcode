//Author: Tong Xu
//Date: 01/03/2020
// Stack solution and s += " ", string preprocess

class Solution {
public:
    int calculate(string s) {
        s += " ";
        stack<int> numStack;
        char sign = '+';
        int sum = 0, num;

        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
            }

            if(s[i] != ' ' || i == s.size() - 1) {
                if(sign == '+') {
                    numStack.push(num);
                }

                else if(sign == '-') {
                    numStack.push(-num);
                }

                else if(sign == '*') {
                    int tmp = numStack.top()*num;
                    numStack.pop();
                    numStack.push(tmp);
                }

                else {
                    int tmp = numStack.top()/num;
                    numStack.pop();
                    numStack.push(tmp);
                }

                sign = s[i];
            }
        }

        while(!numStack.empty()) {
            sum += numStack.top();
            numStack.pop();
        }

        return sum;
    }
};
