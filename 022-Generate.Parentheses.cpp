class Solution {
public:
    void backtrack(int l, int r, string &s, vector<string> &result) {
        if (l == 0 && r == 0)
            result.push_back(s);
        else {
            if (l > 0) {
                s.push_back('(');
                backtrack(l-1, r, s, result);
                s.pop_back();
            }
            if (r - l > 0) {
                s.push_back(')');
                backtrack(l, r-1, s, result);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        backtrack(n, n, s, result);
        return result;
    }
};