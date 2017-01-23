class Solution {
private:
    void backtrack(vector<int> &nums, vector<int> &current, vector<bool> &used, vector<vector<int>> &ans) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1]))
                continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, current, used, ans);
            current.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(n, false);
        sort(nums.begin(), nums.end());
        backtrack(nums, current, used, ans);
        return ans;
    }
};