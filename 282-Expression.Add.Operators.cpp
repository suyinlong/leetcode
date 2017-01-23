class Solution {
private:
    void helper(string &num, int target, string exp, vector<string> &ans, int pos, long long current, long long prev) {
        if (pos == num.size()) {
            if (current == target) ans.push_back(exp);
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (num[pos] == '0' && i > pos) continue;
            string sub = num.substr(pos, i - pos + 1);
            long long cur = stoll(sub);
            if (pos == 0)
                helper(num, target, exp + sub, ans, i + 1, cur, cur);
            else {
                helper(num, target, exp + "+" + sub, ans, i + 1, current + cur, cur);
                helper(num, target, exp + "-" + sub, ans, i + 1, current - cur, -cur);
                helper(num, target, exp + "*" + sub, ans, i + 1, current - prev + prev * cur, prev * cur);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, "", ans, 0, 0, 0);
        return ans;
    }
};