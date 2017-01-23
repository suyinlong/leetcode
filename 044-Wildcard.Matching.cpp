class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while (i < m) {
            if (p[j] == '*') {
                iStar = i;
                jStar = j;
                j++;
            }
            else {
                if (p[j] == s[i] || p[j] == '?') {
                    i++;
                    j++;
                }
                else {
                    if (iStar >= 0) {
                        i = iStar + 1;
                        iStar += 1;
                        j = jStar + 1;
                    }
                    else return false;
                }
            }
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};