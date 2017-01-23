class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return false;
        int a = s1.size(), b = s2.size(), c = s3.size();
        vector<vector<bool>> dp(a + 1, vector<bool>(b + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= a; i++)
            for (int j = 0; j <= b; j++) {
                if (i > 0 && dp[i-1][j] && s3[i+j-1] == s1[i-1])
                    dp[i][j] = true;
                if (j > 0 && dp[i][j-1] && s3[i+j-1] == s2[j-1])
                    dp[i][j] = true;
            }
        return dp[a][b];
    }
};