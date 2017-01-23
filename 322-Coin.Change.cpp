class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++)
            if (dp[i] >= 0)
                for (int c: coins) {
                    long long n = (long long)i + (long long)c;
                    if (n <= amount && (dp[n] == -1 || dp[n] > dp[i] + 1))
                        dp[n] = dp[i] + 1;
                }
        return dp[amount];

    }
};