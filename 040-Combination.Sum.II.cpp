class Solution {
public:
    void backtrack(vector<int> &candidates, int pos, int target, vector<int> &current, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (pos == candidates.size())
            return;

        for (int i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i-1])
                continue;
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                backtrack(candidates, i+1, target-candidates[i], current, result);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, current, result);
        return result;
    }
};