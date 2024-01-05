class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> memo;
        int ans = 0;
        int curSum = 0;
        memo[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (memo.find(curSum - k) != memo.end()) ans += memo[curSum - k];
            if (memo.find(curSum) == memo.end()) memo[curSum] = 1;
            else memo[curSum] += 1;
        }
        return ans;
    }
};