class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int p = n - 1;
        while (p >= 0 && s[p] == ' ') p--;
        if (p < 0) return 0;

        int q = p;
        while (q >= 0 && s[q] != ' ') q--;

        return p - q;

    }
};