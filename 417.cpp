// Author: Tong Xu
// Date: 12/30/2019
// Below solution exceeded time

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vector<vector<int>> visitedPac(m, vector<int>(n, 0));
                vector<vector<int>> visitedAt(m, vector<int>(n, 0));
                if(dfs(matrix, i, j, visitedPac, 0, 0) && dfs(matrix, i, j, visitedAt, m-1, n-1))
                    res.push_back({i, j});
            }
        }
        return res;
    }

private:
    int m;
    int n;

    bool isvalid(int r, int c) {
        return r >= 0 && r < m && c >=0 && c < n;
    }

    bool dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& visited, int rowVal, int colVal) {
        if(r == rowVal || c == colVal) return true;
        if(!isvalid(r, c) || visited[r][c]) return false;

        visited[r][c] = 1;
        bool ret = false;
        if(isvalid(r+1, c) && matrix[r+1][c] <= matrix[r][c])
            ret = ret || dfs(matrix, r+1, c, visited, rowVal, colVal);
        if(isvalid(r-1, c) && matrix[r-1][c] <= matrix[r][c])
            ret = ret || dfs(matrix, r-1, c, visited, rowVal, colVal);
        if(isvalid(r, c+1) && matrix[r][c+1] <= matrix[r][c])
            ret = ret || dfs(matrix, r, c+1, visited, rowVal, colVal);
        if(isvalid(r, c-1) && matrix[r][c-1] <= matrix[r][c])
            ret = ret || dfs(matrix, r, c-1, visited, rowVal, colVal);
        return ret;
    }
};
