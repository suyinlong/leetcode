class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        long long a = labs(dividend);
        long long b = labs(divisor);
        int res = 0;
        while (a >= b) {
            long long t = b;
            long long i;
            for (i = 0; t <= a; i++)
                t <<= 1;
            res += (1 << (i - 1));
            a -= (b << (i - 1));
        }
        return sign == 1 ? res : -res;
    }
};