class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        if (m == 0)
            return true;

        int i = 0, j = 0;
        while (i < m && j < n && n - j >= m - i) {
            if (s[i] == t[j])
                i++;
            j++;
            if (i == m)
                return true;
        }
        return false;
    }
};