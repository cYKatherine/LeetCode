// Add disjoint set solution for https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x]!=x) return find(parent[x], parent);
        return parent[x];
    }
    
    int unionn(int x, int y, vector<int>& parent, vector<int>& count) {
        int xroot = find(x, parent), yroot = find(y, parent);
        if (xroot != yroot) {
            if (count[xroot] >= count[yroot]) {
                parent[yroot] = xroot;
                count[xroot] += count[yroot];
                return count[xroot];
            } else {
                parent[xroot] = yroot;
                count[yroot] += count[xroot];
                return count[yroot];
            }
        }
        return 0;
    }
    
    int inBound(int i, int j, int row, int col) {
        if (i >= 0 && i < row && j >= 0 && j < col) {
            return 1;
        }
        
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> parent(row*col), count(row*col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int index = i*col+j;
                if (grid[i][j]) {
                    count[index] = 1;
                    parent[index] = index;
                }
            }
        }
        int res = 0;
        int direction[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    if (res == 0) res = 1;
                    int index = i*col+j;
                    // if (j+1 < col && grid[i][j+1]) res = max(res, unionn(index, index+1, parent, count));
                    // if (j-1 >= 0 && grid[i][j-1]) res = max(res, unionn(index, index-1, parent, count));
                    // if (i+1 < row && grid[i+1][j]) res = max(res, unionn(index, index+col, parent, count));
                    // if (i-1 >= 0 && grid[i-1][j]) res = max(res, unionn(index, index-col, parent, count));
                    for (auto& dir : direction) {
                        int ni = i+dir[0], nj = j+dir[1];
                        int index = i*col+j, nindex = ni*col+nj;
                        if (inBound(ni, nj, row, col) && grid[ni][nj]) res = max(res, unionn(index, nindex, parent, count));
                    }
                }
            }
        }
        
        return res;
    }
};