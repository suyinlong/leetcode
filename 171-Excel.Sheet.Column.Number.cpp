class Solution {
public:
    int titleToNumber(string s) {
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            n *= 26;
            n += (s[i] - 'A' + 1);
        }
        return n;
    }
};