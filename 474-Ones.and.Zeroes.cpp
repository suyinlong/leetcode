class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string &s: strs) {
            int numZeroes = 0;
            for (char c: s)
                if (c == '0') numZeroes++;
            int numOnes = s.size() - numZeroes;

            for (int i = m; i >= numZeroes; i--) {
                for (int j = n; j >= numOnes; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-numZeroes][j-numOnes] + 1);
                }
            }
        }
        return dp[m][n];
    }
};