class Solution {
public:
    int numSquares(int n) {
        if (n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i * i <= n; i++)
            dp[i*i] = 1;
        for (int i = 1; i <= n; i++)
            if (!dp[i]) {
                dp[i] = INT_MAX;
                for (int j = 1; j * j <= (i >> 1); j++)
                    dp[i] = min(dp[i], dp[j*j] + dp[i-j*j]);
            }
        return dp[n];
    }
};