class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            int ans = 0;
            for (int j = 0; j < i; j++)
                ans += dp[j] * dp[i-1-j];
            dp[i] = ans;
        }
        return dp[n];
    }
};