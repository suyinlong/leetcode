class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int minNums = nums[0], ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minNums)
                ans += nums[i] - minNums;
            else {
                ans += i * (minNums - nums[i]);
                minNums = nums[i];
            }
        }
        return ans;
    }
};