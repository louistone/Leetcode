// Auhtor: Tong Xu
// Date: 1/2/2020
// typical dfs solution, bug initialize count = 0;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        rows = grid.size(), cols = grid[0].size();
        int maxCount = 0, count = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    count = 0;
                    dfs(grid, visited, i, j, count);
                }
                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }

private:
    int rows;
    int cols;
    vector<int> dirs {-1, 0, 1, 0, -1};

    bool isvalid(int r, int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c, int& count) {
        if(!isvalid(r, c) || visited[r][c] || grid[r][c] == 0) return;
        count++;
        visited[r][c] = 1;
        for(int i = 0; i < 4; i++)
            dfs(grid, visited, r+dirs[i], c+dirs[i+1], count);
    }
};
