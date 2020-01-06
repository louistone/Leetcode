// Author: Tong Xu
// Date: 01/06/2020
// LCS and also print out the longest common subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int i, j, len;

        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                dp[i+1][j+1] = text1[i] == text2[j] ? dp[i][j] + 1 : max(dp[i+1][j], dp[i][j+1]);
            }
        }

        string res;
        i = m, j = n, len = dp[m][n];

        while(i >= 1 && j >= 1 && len) {
            if(text1[i-1] == text2[j-1]) {
                res = text1[i-1] + res;
                i--,j--,len--;
            }
            else {
                if(dp[i-1][j] >= dp[i][j-1]) i--;
                else j--;
            }
        }

        //cout << "res: " << res << endl;

        return dp[m][n];
    }
};
