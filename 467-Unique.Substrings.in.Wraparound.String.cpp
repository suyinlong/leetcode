class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if (n == 0)
            return 0;
        vector<int> dp(26, 0);

        int cnt = 1, res = 0;
        for (int i = 1; i < n; i++) {
            if (p[i] == p[i-1] + 1 || (p[i-1] == 'z' && p[i] == 'a')) {
                cnt++;
                continue;
            }
            for (int j = 1; j <= cnt; j++)
                dp[p[i-j] - 'a'] = max(dp[p[i-j] - 'a'], j);
            cnt = 1;
        }
        for (int j = 1; j <= cnt; j++)
            dp[p[n-j] - 'a'] = max(dp[p[n-j] - 'a'], j);
        for (int i = 0; i < 26; i++)
            res += dp[i];
        return res;
    }
};