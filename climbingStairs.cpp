class Solution {
public:
    vector<int> memo;
    int dp(int n) {
        if (memo[n] == -1) {
            if (n == 0 || n == 1) memo[n] = 1;
            else memo[n] = dp(n-1) + dp(n-2);
        }
        return memo[n];
    }
    int climbStairs(int n) {
        memo.resize(n+5);
        fill(memo.begin(), memo.end(), -1);
        return dp(n);
    }
};
