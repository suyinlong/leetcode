class Solution {
private:
    string p = "()";
    void helper(string &s, vector<string> &result, int si, int sj, int dir) {
        int counter = 0;
        for (int i = si; i < s.size(); i++) {
            if (s[i] == p[dir]) counter++;
            else if (s[i] == p[1 - dir]) counter--;
            if (counter < 0) {
                for (int j = sj; j <= i; j++) {
                    if (s[j] == p[1 - dir] && (j == sj || s[j-1] != s[j])) {
                        string t = s.substr(0, j) + s.substr(j + 1);
                        helper(t, result, i, j, dir);
                    }
                }
                return;
            }
        }
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (p[dir] == '(')
            helper(rs, result, 0, 0, 1 - dir);
        else
            result.push_back(rs);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        helper(s, result, 0, 0, 0);
        return result;
    }
};