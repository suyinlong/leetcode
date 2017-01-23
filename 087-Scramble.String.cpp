class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        if (s1.length() != s2.length())
            return false;
        int len = s1.length();
        vector<int> count(256, 0);
        for (int i = 0; i < len; i++) {
            count[s1[i]] ++;
            count[s2[i]] --;
        }
        for (int c: count)
            if (c)
                return false;
        for (int i = 1; i < len; i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, len-i), s2.substr(i, len-i)))
            || (isScramble(s1.substr(0, i), s2.substr(len-i, i)) && isScramble(s1.substr(i, len-i), s2.substr(0, len-i))))
                return true;
        }
        return false;
    }
};