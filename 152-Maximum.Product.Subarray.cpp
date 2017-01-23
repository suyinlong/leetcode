class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int prevMin = nums[0], prevMax = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int a = prevMin * nums[i], b = prevMax * nums[i];
            prevMax = max(nums[i], max(a, b));
            prevMin = min(nums[i], min(a, b));
            ans = max(ans, prevMax);
        }
        return ans;
    }
};