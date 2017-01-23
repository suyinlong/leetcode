class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            int j = 0;
            while (j < nums.size() && nums[j] <= i) {
                dp[i] += dp[i-nums[j]];
                j++;
            }
        }
        return dp[target];
    }
};