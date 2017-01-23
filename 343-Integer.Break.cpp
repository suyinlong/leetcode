class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(max(n + 1, 7), 0);
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        for (int i = 7; i <= n; i++)
            dp[i] = 3 * dp[i-3];
        return dp[n];

    }
};