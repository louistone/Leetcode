// Author: Tong Xu
// Date:  1/2/2020
// 3 submethods solution

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++)
            if(!checkRow(board, row)) return false;
        for(int col = 0; col < 9; col++)
             if(!checkCol(board, col)) return false;
        vector<pair<int, int>> startPoints {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
        for(auto& p : startPoints) {
            if(!checkSquare(board, p.first, p.second)) return false;
        }
        return true;
    }

private:
    bool checkRow(vector<vector<char>>& board, int row) {
        vector<char>& rowNums = board[row];
        unordered_set<char> charSet;
        for(int i = 0; i < 9; i++) {
            char c = rowNums[i];
            if(c == '.') continue;
            if(charSet.count(c)) return false;
            charSet.insert(c);
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, int col) {
        unordered_set<char> charSet;
        for(int i = 0; i < 9; i++) {
            char c = board[i][col];
            if(c == '.') continue;
            if(charSet.count(c)) return false;
            charSet.insert(c);
        }
        return true;
    }

    bool checkSquare(vector<vector<char>>& board, int r, int c) {
        unordered_set<char> charSet;
        for(int i = r; i < r+3; i++) {
            for(int j = c; j < c+3; j++) {
                char c = board[i][j];
                if(c == '.') continue;
                if(charSet.count(c)) return false;
                charSet.insert(c);
            }
        }
        return true;
    }
};
