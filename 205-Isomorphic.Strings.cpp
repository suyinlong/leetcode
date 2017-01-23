class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        if (s.length() <= 1)
            return true;

        vector<char> table(256, 0), rtable(256, 0);

        for (int i = 0; i < s.length(); i++) {
            if (table[s[i]] == 0 && rtable[t[i]] == 0) {
                table[s[i]] = t[i];
                rtable[t[i]] = s[i];
            }
            else if (table[s[i]] != t[i])
                return false;
        }
        return true;
    }
};