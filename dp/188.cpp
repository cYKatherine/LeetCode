// Solution for https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        
        for (int kk = 1; kk <= k; kk++) {
            int maxTmp = 0 - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                dp[kk][i] = max(dp[kk][i-1], prices[i] + maxTmp);
                maxTmp = max(maxTmp, dp[kk-1][i] - prices[i]);
            }
        }
        
        return dp[k][prices.size()-1];
    }
};