class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> isVisited(26, false);
        stack<char> stk;
        for (char c: s)
            count[c-'a']++;
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a'] --;
            if (isVisited[s[i] - 'a']) continue;
            while (!stk.empty() && stk.top() > s[i] && count[stk.top() - 'a'] > 0) {
                isVisited[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(s[i]);
            isVisited[s[i] - 'a'] = true;

        }
        string r;
        while (!stk.empty()) {
            r.push_back(stk.top());
            stk.pop();
        }
        reverse(r.begin(), r.end());
        return r;
    }
};