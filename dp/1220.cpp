// Add solution for https://leetcode.com/problems/count-vowels-permutation/

typedef long long ll;
class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<ll>> memo;

    int countVowelPermutation(int n) {
        memo.resize(n+1, vector<ll>(5, 0));
        ll ans = 0;
        ans += dp(n, 0)%MOD + dp(n, 1)%MOD + dp(n, 2)%MOD + dp(n, 3)%MOD + dp(n, 4)%MOD;
        return ans%MOD;
    }
    
    ll dp(int n, int end) {
        // a: 0, e: 1, i: 2, o: 3, u: 4
        if (memo[n][end]) return memo[n][end];
        if (n == 1) return memo[n][end] = 1;
        long long ans = 0;
        if (end == 0) ans += dp(n-1, 1)%MOD;
        else if (end == 1) ans += dp(n-1, 0)%MOD + dp(n-1, 2)%MOD;
        else if (end == 2) ans += dp(n-1, 0)%MOD + dp(n-1, 1)%MOD + dp(n-1, 3)%MOD + dp(n-1, 4)%MOD;
        else if (end == 3) ans += dp(n-1, 2)%MOD + dp(n-1, 4)%MOD;
        else if (end == 4) ans += dp(n-1, 0)%MOD;
        return memo[n][end] = ans%MOD;
    }
};