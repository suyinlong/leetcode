class Solution {
private:
    void backtrack(string &p, string &current, vector<bool> &used, vector<string> &ans, char oddChar) {
        if (current.size() == p.size()) {
            ans.push_back(current);
            if (oddChar >= 0) ans.back() += oddChar;
            string rp(current);
            reverse(rp.begin(), rp.end());
            ans.back() += rp;
            return;
        }
        for (int i = 0; i < p.size(); i++) {
            if (used[i] || (i > 0 && p[i] == p[i-1] && !used[i-1])) continue;
            used[i] = true;
            current += p[i];
            backtrack(p, current, used, ans, oddChar);
            current.pop_back();
            used[i] = false;
        }

    }
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        vector<int> count(256, 0);
        for (char c: s)
            count[c] ++;
        int odd = 0;
        char oddChar = -1;
        string p = "";
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                for (int j = 0; j < (count[i] >> 1); j++)
                    p += (char)i;
            }
            if (count[i] % 2 == 1) {
                oddChar = i;
                odd++;
                if (odd > 1) return ans;
            }
        }
        string current = "";
        vector<bool> used(p.size(), false);
        backtrack(p, current, used, ans, oddChar);
        return ans;

    }
};