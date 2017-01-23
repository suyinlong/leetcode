class Solution {
private:
    void backtrack(vector<int> &nums, vector<int> &current, vector<vector<int>> &result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int c: nums) {
            if (find(current.begin(), current.end(), c) == current.end()) {
                current.push_back(c);
                backtrack(nums, current, result);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, current, result);
        return result;
    }
};