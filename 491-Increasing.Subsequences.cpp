class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        pick(0, nums, current, res);
        return res;
    }
private:
    void pick(int pos, vector<int> &nums, vector<int> &current, vector<vector<int>> &res) {
        if (current.size() > 1)
            res.push_back(current);
        unordered_set<int> used;
        for (int i = pos; i < nums.size(); i++) {
            if (current.size() > 0 && current.back() > nums[i]) continue;
            if (used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);
            current.push_back(nums[i]);
            pick(i + 1, nums, current, res);
            current.pop_back();
        }
    }
};