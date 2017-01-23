class Solution {
public:
    int longestValidParentheses(string s) {
        s = ")" + s;
        int n = s.size();
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '(')
                dp[i] = 0;
            else {
                if (s[i-1] == '(')
                    dp[i] = dp[i-2] + 2;
                else if (s[i-dp[i-1]-1] == '(')
                    dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                res = max(res, dp[i]);
            }
        }
        return res;
    }
/*
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        if (n < 2) return res;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if ('(' == s[i])
                stk.push(i);
            else {
                if (stk.empty())
                    stk.push(i);
                else {
                    if (s[stk.top()] == '(') {
                        stk.pop();
                        res = max(res, i - (stk.empty() ? -1 : stk.top()));
                    }
                    else
                        stk.push(i);
                }
            }
        }
        return res;
    }
*/
};