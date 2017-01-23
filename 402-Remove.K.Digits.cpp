class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == 0 || k == 0)
            return num;
        if (num.size() == k)
            return "0";

        stack<char> s;

        for (int i = 0; i < num.size(); i++) {
            char c = num[i];
            if (s.empty() || s.top() <= c)
                s.push(c);
            else {
                while (!s.empty() && s.top() > c && k > 0) {
                    s.pop();
                    k--;
                }
                s.push(c);
            }
        }
        while (k > 0) {
            s.pop();
            k--;
        }
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        while (ans.back() == '0')
            ans.pop_back();

        reverse(ans.begin(), ans.end());
        return ans.size() == 0 ? "0" : ans;
    }
};