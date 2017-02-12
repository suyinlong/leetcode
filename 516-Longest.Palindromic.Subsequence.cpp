class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l <= n - len; l++) {
                int r = l + len - 1;
                if (l == r) dp[l][r] = 1;
                else if (l + 1 == r) dp[l][r] = s[l] == s[r] ? 2 : 1;
                else {
                    int f = s[l] == s[r] ? 2 : 0;
                    dp[l][r] = max(dp[l+1][r-1] + f, max(dp[l][r-1], dp[l+1][r]));
                }
            }
        }
        return dp[0][n-1];
    }
};