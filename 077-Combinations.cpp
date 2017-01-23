class Solution {
public:
    void backtrack(int n, int k, int pos, vector<int> &current, vector<vector<int>> &result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        if (pos > n)
            return;
        current.push_back(pos);
        backtrack(n, k, pos+1, current, result);
        current.pop_back();
        backtrack(n, k, pos+1, current, result);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(n, k, 1, current, result);
        return result;
    }
};