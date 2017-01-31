class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefixSum[i+1] = prefixSum[i] + nums[i];
        int winning = prefixSum[n] / 2 + prefixSum[n] % 2;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (l == r)
                    dp[l][r] = nums[l];
                else if (l == r - 1)
                    dp[l][r] = max(nums[l], nums[r]);
                else {
                    int pLeft = nums[l] + prefixSum[r+1] - prefixSum[l+1] - dp[l+1][r];
                    int pRight = nums[r] + prefixSum[r] - prefixSum[l] - dp[l][r-1];
                    dp[l][r] = max(pLeft, pRight);
                }
            }
        }
        return dp[0][n-1] >= winning;
    }
};