class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (dp[i])
                for (int len = 1; len < n - i + 1; len++)
                    if (wordDict.find(s.substr(i, len)) != wordDict.end())
                        dp[i + len] = true;
        }
        return dp[n];
    }
};