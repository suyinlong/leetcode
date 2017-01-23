class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        sum >>= 1;

        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (int k: nums) {
            for (int j = sum; j >= 1; j--)
                if (j >= k)
                    dp[j] = dp[j] || dp[j-k];
        }

        return dp[sum];
    }
};