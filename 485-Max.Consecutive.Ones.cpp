class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return 0;
        int dp = (nums[0] == 1), res = dp;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 1)
                dp++;
            else
                dp = 0;
            res = max(res, dp);
        }
        return res;
    }
};