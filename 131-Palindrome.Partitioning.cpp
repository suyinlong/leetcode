class Solution {
public:
    void partitionHelper(int pos, string &s, vector<vector<bool>> &dp, vector<string> &current, vector<vector<string>> &result) {
        if (pos == s.length())
            result.push_back(current);
        for (int i = pos; i < s.length(); i++)
            if (dp[pos][i]) {
                current.push_back(s.substr(pos,  i-pos+1));
                partitionHelper(i+1, s, dp, current, result);
                current.pop_back();
            }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

        for (int len = 1; len <= s.length(); len++)
            for (int i = 0; i < s.length() - len + 1; i++) {
                if (len == 1)
                    dp[i][i] = true;
                else if (len == 2)
                    dp[i][i+1] = (s[i] == s[i+1]);
                else
                    dp[i][i+len-1] = (dp[i+1][i+len-2] && (s[i] == s[i+len-1]));
            }

        vector<vector<string>> result;
        vector<string> current;
        partitionHelper(0, s, dp, current, result);
        return result;
    }
};