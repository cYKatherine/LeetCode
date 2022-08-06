// Solution for https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> newNums(nums.size()+2, 1);
        for (int i = 0; i < nums.size(); i++) newNums[i+1]=nums[i];
        vector<vector<int>> memo(nums.size()+2, vector<int>(nums.size()+2, -1));
        return dp(0, nums.size()+1, newNums, memo);
    }
    
    int dp(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if (memo[left][right] != -1) return memo[left][right];
        int res = 0;
        if (left+1 == right) res = 0;
        else {  
            for (int i = left+1; i < right; i++) {
                res = max(dp(left, i, nums, memo)+nums[left]*nums[i]*nums[right]+dp(i, right, nums, memo), res);
            }
        }
        return memo[left][right]=res;
    }
};