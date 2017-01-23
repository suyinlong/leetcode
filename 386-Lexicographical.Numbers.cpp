class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        fill(1, n, ans);
        return ans;
    }
    void fill(int p, int n, vector<int> &ans) {
        if (p > n)
            return;
        ans.push_back(p);
        fill(p * 10, n, ans);
        if (p % 10 != 9) fill(p + 1, n, ans);
    }
};