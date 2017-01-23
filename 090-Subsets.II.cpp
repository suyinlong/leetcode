class Solution {
public:
    void generateSub(vector<int> &nums, int pos, vector<int> &current, vector<vector<int>> &result) {
        for (int i = pos; i < nums.size(); i++) {
            current.push_back(nums[i]);
            result.push_back(current);
            if (i < nums.size() - 1)
                generateSub(nums, i + 1, current, result);
            current.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        result.push_back(current);
        if (nums.size() == 0)
            return result;
        sort(nums.begin(), nums.end());

        generateSub(nums, 0, current, result);
        return result;
    }

};