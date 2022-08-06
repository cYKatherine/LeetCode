// Solution for https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size());
        for (int i = 0; i < grid.size(); i++) {
            memo[i].resize(grid[0].size(), 0);
        }
        
        
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] && !memo[i][j]) {
                    res = max(res, dfs(i, j, memo, grid));
                }
            }
        }
        return res;
    }
    
    int dfs(int i, int j, vector<vector<int>>& memo, vector<vector<int>>& grid) {
        if (i < 0 || i >= memo.size() || j < 0 || j >= memo[0].size()) return 0;
        int res = 0;
        if (!memo[i][j]) {
            memo[i][j] = 1;
            if (grid[i][j]) {
                res += 1;
                res += dfs(i+1, j, memo, grid);
                res += dfs(i-1, j, memo, grid);
                res += dfs(i, j+1, memo, grid);
                res += dfs(i, j-1, memo, grid);
            }
        }
        return res;
    }
};