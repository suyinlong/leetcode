class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length(), n = t.length();
        if (m - n > 1 || m - n < -1 || s == t)
            return false;
        if (m == n) {
            int diff = 0;
            for (int i = 0; i < m; i++)
                if (s[i] != t[i])   diff++;
            if (diff != 1)
                return false;
            return true;
        }
        else {
            int i = 0, j = 0;
            while (s[i] == t[j]) {
                i++; j++;
            }
            if (m > n)  i++;
            else    j++;
            while (i < m && j < n) {
                if (s[i] != t[j])   return false;
                i++; j++;
            }
            return true;
        }

    }
};