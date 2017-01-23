class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                if (len == 1) {
                    dp[i][i+1] = i;
                    continue;
                }
                int r = INT_MAX;
                for (int k = i; k <= i + len; k++) {
                    r = min(r, k + max(dp[i][k-1], dp[k+1][i+len]));
                }
                dp[i][i+len] = r;
            }
        }
        return dp[1][n];
    }
};