class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                int dReplace = dp[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 1);
                int dAddDel = min(dp[i-1][j], dp[i][j-1]) + 1;
                dp[i][j] = min(dAddDel, dReplace);
            }
        return dp[m][n];
    }
};