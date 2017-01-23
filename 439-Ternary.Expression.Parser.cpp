class Solution {
public:
    string parseTernary(string expression) {
        if (expression.size() == 0) return "";
        stack<char> stk;
        for (int i = expression.size() - 1; i >= 0; i--) {
            if (expression[i] == '?') {
                char a = stk.top(); stk.pop();
                char b = stk.top(); stk.pop();
                if (expression[i-1] == 'T') stk.push(a);
                else stk.push(b);
                i--;
            }
            else if (expression[i] == ':') continue;
            else stk.push(expression[i]);
        }
        string result;
        result += stk.top();
        return result;
    }
};