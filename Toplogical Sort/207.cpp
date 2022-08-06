// Add solution for https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> memo(numCourses);
        for (vector<int>& pre : prerequisites) memo[pre[0]].push_back(pre[1]);
        
        vector<int> visited(numCourses, 0);
        vector<int> ans(numCourses, 0);
        bool res = true;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                res &= dfs(i, visited, ans, memo);
                if (!res) return res;
            }
        }
        return res;
    }
    
    bool dfs(int i, vector<int>& visited, vector<int>& ans, vector<vector<int>>& memo) {
        if (visited[i]) return ans[i];
        visited[i] = true;
        bool res = true;
        for (int pre : memo[i]) {
            res &= dfs(pre, visited, ans, memo);
        }
        return ans[i] = res;
    }
};