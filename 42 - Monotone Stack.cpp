// Monotone stack solution for https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int area = 0;
        for (int i = 0; i < height.size(); i++) {
            if (!s.empty() && height[i] > height[s.top()]) {
                int right = height[i], mid = height[s.top()], midIndex = s.top(), rightIndex = i;
                while (!s.empty() && height[s.top()] == mid) s.pop();
                while (!s.empty() && height[s.top()] >= mid && mid < right) {
                    int left = height[s.top()], leftIndex = s.top();
                    area += (rightIndex - leftIndex - 1) * (min(left, right) - mid);
                    if (left >= right) {
                        mid = right;
                        midIndex = rightIndex;
                    } else {
                        mid = left;
                        midIndex = leftIndex;
                        s.pop();
                    }
                }
            }
            s.push(i);
        }
        return area;
    }
};