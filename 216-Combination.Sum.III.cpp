class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;

        dfs(1, k,n, tmp, ans);
        return ans;
    }

    void dfs(int idx, int k, int n, vector<int> &tmp, vector<vector<int>> &ans) {
        if (n == 0 && tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if (idx > 9)
            return;
        for (int i = idx; i < 10; i++) {
            tmp.push_back(i);
            dfs(i + 1, k, n - i, tmp, ans);
            tmp.pop_back();
        }
    }
};