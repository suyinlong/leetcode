class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].size() == 1 && tokens[i][0] < '0') {
                int a = numStack.top();
                numStack.pop();
                int b = numStack.top();
                numStack.pop();
                switch (tokens[i][0]) {
                    case '+':
                        numStack.push(b + a);
                        break;
                    case '-':
                        numStack.push(b - a);
                        break;
                    case '*':
                        numStack.push(b * a);
                        break;
                    case '/':
                        numStack.push(b / a);
                        break;
                }
            }
            else
                numStack.push(stoi(tokens[i]));
        }
        return numStack.top();
    }
};