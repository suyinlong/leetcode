class Solution {
private:
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string comb(digits.size(), ' ');
        backtrack(0, digits, comb, ans);
        return ans;
    }
    void backtrack(int n, string &digits, string &comb, vector<string> &ans) {
        if (n == digits.size()) {
            ans.push_back(comb);
            return;
        }
        for (int i = 0; i < letters[digits[n] - '0'].size(); i++) {
            comb[n] = letters[digits[n] - '0'][i];
            backtrack(n + 1, digits, comb, ans);
            comb[n] = ' ';
        }
    }
};