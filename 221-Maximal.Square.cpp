class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<int> dp(matrix[0].size(), 0);
        int m = 0, old;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++) {
                int temp = dp[j];
                if (matrix[i][j] == '0')
                    dp[j] = 0;
                else if (i == 0 || j == 0)
                    dp[j] = 1;
                else {
                    dp[j] = min(dp[j-1], min(old, dp[j])) + 1;
                }
                m = max(dp[j], m);
                old = temp;
            }
        return m * m;
    }
};