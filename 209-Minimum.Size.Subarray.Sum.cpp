class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int i = 0, j = 0, sum = nums[0], n = nums.size(), ans = INT_MAX;

        while (j < n) {
            if (sum < s) {
                j++;
                sum += nums[j];
                continue;
            }
            ans = min(ans, j - i + 1);
            sum -= nums[i];
            i++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};