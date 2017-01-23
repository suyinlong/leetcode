class Solution {
public:
    int calculate(string s) {
        int ans = 0, sign = 1, num = 0;
        stack<int> nums, ops;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c >= '0'  && c <= '9')
                num = num * 10 + (c - '0');
            else {
                ans += sign * num;
                num = 0;
                if (c == '+')
                    sign = 1;
                if (c == '-')
                    sign = -1;
                if (c == '(') {
                    nums.push(ans);
                    ops.push(sign);
                    ans = 0;
                    sign = 1;
                }
                if (c == ')' && !ops.empty()) {
                    ans = ops.top() * ans + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
        }
        ans += sign * num;
        return ans;
    }
};