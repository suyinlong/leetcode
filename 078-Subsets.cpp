class Solution {
private:
    void backtrack(vector<int> &nums, int pos, vector<int> &c, vector<vector<int>> &ans) {
        if (pos == nums.size()) {
            ans.push_back(c);
            return;
        }
        backtrack(nums, pos + 1, c, ans);
        c.push_back(nums[pos]);
        backtrack(nums, pos + 1, c, ans);
        c.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(nums, 0, current, ans);
        return ans;
    }
};