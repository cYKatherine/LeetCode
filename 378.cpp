// Solution for https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (maxHeap.size() <= k || matrix[i][j] <= maxHeap.top()) maxHeap.push(matrix[i][j]);
                else minHeap.push(matrix[i][j]);
                
                if (maxHeap.size() > k) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
        }
        
        return maxHeap.top();
    }
};