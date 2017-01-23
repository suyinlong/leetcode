class Solution {
public:
    string multiply(string num1, string num2) {
        string result;
        int m = num1.size(), n = num2.size();
        vector<int> mul(m+n, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                mul[i+j] += (num1[i] - '0') * (num2[j] - '0');
                mul[i+j+1] += mul[i+j] / 10;
                mul[i+j] = mul[i+j] % 10;
            }
        int k = m+n-1;
        while (k > 0 && mul[k] == 0) k--;
        while (k >= 0) {
            result += (mul[k] + '0');
            k--;
        }
        return result;
    }
};