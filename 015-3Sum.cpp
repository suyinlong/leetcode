class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int l = i + 1, r = len - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    vector<int> current = {nums[i], nums[l], nums[r]};
                    ans.push_back(current);
                    l++; r--;
                    while (l < r && nums[l] == nums[l-1]) l++;
                    while (l < r && nums[r] == nums[r+1]) r--;
                }
                else if (nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};