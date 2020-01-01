//Author: Tong Xu
//Date: 12/31/2019

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> res;

        for(int i = 0; i < m; i++) {
            dfs(matrix, pacific, i, 0, INT_MIN);
            dfs(matrix, atlantic,i, n-1, INT_MIN);
        }

        for(int i =  0; i < n; i++) {
            dfs(matrix, pacific, 0, i, INT_MIN);
            dfs(matrix, atlantic, m-1, i, INT_MIN);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

private:
    int m;
    int n;

    bool isvalid(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    vector<int> dirs {-1, 0, 1, 0, -1};

    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int r, int c, int height) {
        if(!isvalid(r, c) || height > matrix[r][c] || visited[r][c]) return;

        visited[r][c] = 1;
        for(int i = 0; i < 4; i++)
            dfs(matrix, visited, r+dirs[i], c+dirs[i+1], matrix[r][c]);
    }
};
