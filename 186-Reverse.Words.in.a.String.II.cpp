class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() <= 1)
            return;
        reverse(s.begin(), s.end());

        int i = 0, j = 0;
        while (j < s.length()) {
            while (s[j] != ' ' && j < s.length())
                j++;
            reverse(s.begin() + i, s.begin() + j);
            j++;
            i = j;
        }
    }
};