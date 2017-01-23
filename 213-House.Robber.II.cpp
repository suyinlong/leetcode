class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                dp[0] = nums[0];
            else if (i == 1)
                dp[1] = max(nums[0], nums[1]);
            else
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int r1 = dp[nums.size() - 2];

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                dp[0] = 0;
            else if (i == 1)
                dp[1] = nums[1];
            else if (i == 2)
                dp[2] = max(nums[1], nums[2]);
            else
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int r2 = dp[nums.size() -1];
        return max(r1, r2);
    }
};