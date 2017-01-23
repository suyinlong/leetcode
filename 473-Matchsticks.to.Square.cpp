class Solution {
public:
    bool makesquare(vector<int>& nums) {
        const int n = nums.size();
        if (n < 4) return false;
        int sum = 0;
        for (int k: nums) sum += k;
        if (sum % 4 != 0) return false;

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        vector<int> sums(4, 0);
        return dfs(nums, 0, sums, sum >> 2);
    }
    bool dfs(vector<int> &nums, int idx, vector<int> &sums, int target) {
        if (sums[0] == target && sums[1] == target && sums[2] == target)
            return true;
        if (idx == nums.size())
            return false;
        for (int i = 0; i < 4; i++) {
            if (sums[i] + nums[idx] > target) continue;
            sums[i] += nums[idx];
            if (dfs(nums, idx + 1, sums, target)) return true;
            sums[i] -= nums[idx];
        }
        return false;
    }
};