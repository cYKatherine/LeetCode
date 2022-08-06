// Add solution for https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses, 0), res;
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            degree[pre[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!degree[i]) q.push(i);
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            degree[cur]--;
            
            for (auto& next : adj[cur]) {
                degree[next]--;
                if (!degree[next]) q.push(next);
            }
        }
        
        for (auto& d : degree) {
            if (d > 0) return {};
        }
        return res;
    }
};