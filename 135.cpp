// Solution for https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> memo(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) memo[i] = memo[i-1] + 1;
        }
        
        for (int i = ratings.size()-1; i > 0; i--) {
            if (ratings[i] < ratings[i-1]) memo[i-1] = max(memo[i] + 1, memo[i-1]);
        }
        
        int res = 0;
        for (int i = 0; i < ratings.size(); i++) res += memo[i];
        return res;
    }
};