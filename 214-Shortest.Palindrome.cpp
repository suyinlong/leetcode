class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;

        string srev(s);
        reverse(srev.begin(), srev.end());
        string ss = s + "#" + srev;
        int longest = kmp(ss);

        if (longest == n)
            return s;
        return srev.substr(0, n-longest) + s;
    }
private:
    int kmp(string s) {
        int len = s.size();
        vector<int> table(len, 0);
        int idx = 0;
        for (int i = 1; i < len; i++) {
            if (s[idx] == s[i]) {
                table[i] = table[i-1] + 1;
                idx++;
            }
            else {
                idx = table[i-1];
                while (idx > 0 && s[idx] != s[i])
                    idx = table[idx-1];
                if (s[idx] == s[i])
                    idx++;
                table[i] = idx;
            }
        }
        return table[len - 1];
    }
};