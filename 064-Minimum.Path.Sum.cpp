class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
        dp[1][0] = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[i+1][j+1] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
        return dp[m][n];
    }
};