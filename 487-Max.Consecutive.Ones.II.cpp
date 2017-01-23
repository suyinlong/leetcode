class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return 0;
        int dp0 = (nums[0] == 1), dp1 = 1, res = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 1) {
                dp0++;
                dp1++;
            }
            else {
                dp1 = dp0 + 1;
                dp0 = 0;
            }
            res = max(res, dp0);
            res = max(res, dp1);
        }
        return res;
    }
};