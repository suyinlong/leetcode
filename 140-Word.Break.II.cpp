class Solution {
private:
    void generateCut(vector<vector<int>> &dp, int n, string &s, vector<string> &cut, vector<string> &result) {
        if (n == 0) {
            string ans;
            for (auto it = cut.rbegin(); it != cut.rend(); it ++)
                ans += *it + " ";
            result.push_back(ans.substr(0, ans.length() - 1));
            return;
        }
        for (auto it = dp[n].begin(); it != dp[n].end(); it++) {
            cut.push_back(s.substr(*it, n - *it));
            generateCut(dp, *it, s, cut, result);
            cut.pop_back();
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        int n = s.length();
        if (n == 0)
            return result;
        vector<vector<int>> dp(n + 1, vector<int>());
        dp[0].push_back(0);

        for (int i = 0; i < n; i++) {
            if (dp[i].size() > 0) {
                for (int len = 1; len < n - i + 1; len++) {
                    if (wordDict.count(s.substr(i, len)))
                        dp[i + len].push_back(i);
                }
            }
        }

        if (dp[n].size() == 0)
            return result;
        vector<string> cut;
        generateCut(dp, n, s, cut, result);
        return result;
    }
};