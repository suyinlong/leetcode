class Solution {
private:
    vector<string> sHelper(int n) {
        if (n == 0) {
            vector<string> ans = {""};
            return ans;
        }
        if (n == 1) {
            vector<string> ans = {"0", "1", "8"};
            return ans;
        }
        else {
            vector<string> r = sHelper(n - 2);
            vector<string> ans;
            for (int i = 0; i < r.size(); i++) {
                ans.push_back("0" + r[i] + "0");
                ans.push_back("1" + r[i] + "1");
                ans.push_back("6" + r[i] + "9");
                ans.push_back("8" + r[i] + "8");
                ans.push_back("9" + r[i] + "6");
            }
            return ans;
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> r = sHelper(n);
        vector<string> ans;
        for (int i = 0; i < r.size(); i++) {
            if (r[i][0] == '0' && n > 1)
                continue;
            ans.push_back(r[i]);
        }
        return ans;
    }
};