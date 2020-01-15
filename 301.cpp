// Date: 1/14/2019
// Author: Tong Xu


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        int left = 0, right = 0;
        for(const auto& c : s) {
//             if(c != '(' && c != ')')
//                 continue;
//             if(c == '(') {
//                 left++;
//             }

//             else {
//                 if(left > 0) {
//                     left--;
//                 }
//                 else {
//                     right++;
//                 }
//             }
            if(c == '(') left++;
            else if(c == ')') {
                if(left > 0) left--;
                else right++;
            }
        }

        //cout << "left: " << left << endl;
        //cout << "right: " << right << endl;

        dfs(0, left, right, "", res, 0, s);

        //cout << "res: " << res.size() << endl;

        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(int pair, int left, int right, string cur, unordered_set<string>& res, int index, string& s) {
        if(index == s.size()) {
            if(pair == 0 && left == 0 && right == 0) res.insert(cur);
            return;
        }

        if(s[index] == '(') {
            // keep it
            dfs(pair+1, left, right, cur+s[index], res, index+1, s);

            // remove it
            if(left > 0) dfs(pair, left-1, right, cur, res, index+1, s);
        }

        else if(s[index] == ')') {
            // keep it
            if(pair > 0)  dfs(pair-1, left, right, cur+s[index], res, index+1, s);

            // remove it
            if(right > 0) dfs(pair, left, right-1, cur, res, index+1, s); // this line of code cause bug cur not cur+s[index]
        }

        else dfs(pair, left, right, cur+s[index], res, index+1, s);
    }
};
