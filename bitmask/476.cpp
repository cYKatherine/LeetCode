// Solution for https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        string s = "";
        while (num > 0) {
            s.push_back(1 - num % 2 + '0');
            num /= 2;
        }
        reverse(s.begin(), s.end());
        return stoi(s, nullptr, 2);
    }
};