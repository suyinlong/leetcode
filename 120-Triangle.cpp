class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;
        vector<int> dp(1, triangle[0][0]);

        for (int i = 1; i < triangle.size(); i++) {
            dp.push_back(dp.back() + triangle[i][i]);
            for (int j = i - 1; j > 0; j--)
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            dp[0] = dp[0] + triangle[i][0];
        }
        int ans = INT_MAX;
        for (int k: dp)
            ans = min(ans, k);
        return ans;
    }
};