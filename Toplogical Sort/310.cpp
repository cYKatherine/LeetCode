// Add solution for https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0), visited(n, 0), res;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int> q;
        int remaining = n;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
                degree[i] = -1;
            }
        }
        
        while (!q.empty()) {
            res.clear();
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();

                if (!visited[cur]) {
                    visited[cur] = 1;
                    res.push_back(cur);
                    for (auto& next : adj[cur]) {
                        degree[next]--;
                        if (degree[next] == 1) q.push(next);
                    }
                }
            }
        }
        return res;
    }
};