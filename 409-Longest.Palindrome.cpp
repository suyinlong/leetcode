class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(52, 0);
        for (char c: s) {
            if (c >= 'A' && c <= 'Z')
                count[c - 'A']++;
            if (c >= 'a' && c <= 'z')
                count[c - 'a' + 26]++;
        }
        bool odd = false;
        int r = 0;
        for (int k: count) {
            if (k & 1 == 1)
                odd = true;
            r += (k >> 1) << 1;
        }
        return odd ? r + 1 : r;

    }
};