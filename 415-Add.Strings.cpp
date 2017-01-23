class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        int carry = 0, sum = 0, i = 1;

        string ans = "";
        while (m - i >= 0 || n - i >= 0) {
            int a = (m - i >= 0) ? num1[m-i] - '0' : 0;
            int b = (n - i >= 0) ? num2[n-i] - '0' : 0;
            sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            ans += (sum + '0');
            i++;
        }
        if (carry > 0)
            ans += (carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};