// Solution for https://leetcode.com/problems/number-of-excellent-pairs/

class Solution {
public:
    int setBits(int num) {
        int cnt = 0;
        while (num) {
            if (num%2) cnt++;
            num /= 2;
        }
        return cnt;
    }

    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> memo;
        for (auto& x: s) {
            memo.push_back(setBits(x));
        }
        sort(memo.begin(), memo.end());
        
        long long res = 0;
        for (int i = 0; i < memo.size(); i++) {
            res += (memo.end() - lower_bound(memo.begin(), memo.end(), k-memo[i]));
        }
        return res;
    }
};