// Solution for https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int k = 1; k <= 2; k++) {
            int minSpent = prices[0];
            for (int i = 1; i < prices.size(); i++) {
                minSpent = min(minSpent, prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - minSpent);
            }
        }
        return dp[2][prices.size()-1];
    }
};