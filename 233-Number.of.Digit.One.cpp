class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long m = 1; m <= n; m *= 10)
            res += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
        return res;
    }
};