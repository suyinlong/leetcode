class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;

        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target, tmp, ans);
        return ans;
    }
    void dfs(int idx, vector<int> &c, int target, vector<int> &tmp, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < c.size(); i++) {
            if (c[i] > target)
                break;
            tmp.push_back(c[i]);
            dfs(i, c, target - c[i], tmp, ans);
            tmp.pop_back();
        }
    }
};