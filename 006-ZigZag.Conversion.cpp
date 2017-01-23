class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int m = 2 * numRows - 2, n = s.size(), p = 0;
        string ans(s.size(), ' ');
        for (int i = 0; i <= m; i += 2) {
            int idx = i >> 1, lastidx = -1;
            while (idx < n) {
                if (lastidx != idx && idx < n)
                    ans[p++] = s[idx];
                lastidx = idx;
                idx += m - i;
                if (lastidx != idx && idx < n)
                    ans[p++] = s[idx];
                lastidx = idx;
                idx += i;
            }
        }
        return ans;

    }
};