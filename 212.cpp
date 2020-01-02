// Author: Tong Xu
// Date: 1/1/2019
// bug: variable naming w is better named as word

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        if(board.empty()) return {};
        m = board.size(), n = board[0].size();
        unordered_set<char> charSet;
        vector<string> res;

        for(auto& v : board)
            for(auto& c : v)
                charSet.insert(c);

        for(auto& w : words) {
            if(charSet.count(w[0])) {
                bool check = true;
                for(int i = 0; i < m && check; i++) {
                    for(int j = 0; j < n && check; j++) {
                        if(board[i][j] == w[0]) {
                            if(dfs(board, w, 0, i, j, check)) {
                                res.push_back(w);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }

private:
    int m;
    int n;
    vector<int> dirs {-1, 0, 1, 0, -1};
    bool isvalid(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    bool dfs(vector<vector<char>>& board, string& word, int pos, int r, int c, bool& check) {
        if(pos == word.size()) {
            check = false;
            return true;
        }

        if(!isvalid(r, c) || board[r][c] != word[pos]) return false;

        char tmp = board[r][c];
        board[r][c] = '#';
        bool ret = false;
        for(int i = 0; i < 4; i++)
            ret = ret || dfs(board, word, pos+1, r+dirs[i], c+dirs[i+1], check);
        board[r][c] = tmp;

        return ret;
    }
};
