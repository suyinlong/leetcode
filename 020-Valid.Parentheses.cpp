class Solution {
public:
    bool isValid(string s) {
        stack<int> v;

        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                    v.push(0);
                    break;
                case '[':
                    v.push(1);
                    break;
                case '{':
                    v.push(2);
                    break;
                case ')':
                    if (v.empty() || v.top() != 0)
                        return false;
                    v.pop();
                    break;
                case ']':
                    if (v.empty() || v.top() != 1)
                        return false;
                    v.pop();
                    break;
                case '}':
                    if (v.empty() || v.top() != 2)
                        return false;
                    v.pop();
                    break;
            }
        }

        return (v.empty());
    }
};