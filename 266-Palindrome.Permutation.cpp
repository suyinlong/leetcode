class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> count(256, 0);
        for (char c: s)
            count[c] ++;
        int odd = 0, even = 0;
        for (int k: count)
            if (k % 2 == 0) even++;
            else odd++;
        return (odd == 0) || (odd == 1);
    }
};