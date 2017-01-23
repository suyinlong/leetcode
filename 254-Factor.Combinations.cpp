class Solution {
private:
    void getFactors(int p, int n, vector<int> &current, vector<vector<int>> &ans) {
        if (n == 1) {
            if (current.size() > 1)
                ans.push_back(current);
            return;
        }
        for (int i = p; i <= n; i++) {
            if (n % i == 0) {
                current.push_back(i);
                getFactors(i, n / i, current, ans);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> current;

        getFactors(2, n, current, ans);
        return ans;
    }
};