class Solution {
    struct fsEntry {
        int level;
        int length;
        fsEntry(int lev, int len): level(lev), length(len) {}
    };
public:
    int lengthLongestPath(string input) {
        int m = 0;
        stack<fsEntry> fsStack;

        string s;
        int level = 0;

        for (int i = 0; i <= input.length(); i++) {
            if (i == input.length() || input[i] == '\n') {
                while (!fsStack.empty() && fsStack.top().level >= level)
                    fsStack.pop();
                int length = (level == 0 ? 0 : 1 + fsStack.top().length) + s.length();
                if (s.find(".") != string::npos)
                    m = max(m, length);
                else {
                    fsEntry f(level, length);
                    fsStack.push(f);
                }
                level = 0;
                s = "";
            }
            else if (input[i] == '\t')
                level++;
            else
                s += input[i];
        }
        return m;
    }
};