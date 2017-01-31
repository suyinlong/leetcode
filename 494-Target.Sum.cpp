class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (((total + S) & 1) || total < S)
            return 0;
        total = (total + S) >> 1;

        vector<int> dp(total + 1, 0);
        dp[0] = 1;
        for (int n: nums) {
            for (int i = total; i >= n; i--)
                dp[i] += dp[i-n];
        }
        return dp[total];
    }
};