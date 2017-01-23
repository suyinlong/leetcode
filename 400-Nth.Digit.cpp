class Solution {
public:
    int findNthDigit(int n) {
        long long p = 0, q = 0, k = 0, l = 9;
        while (q < (long long)n) {
            p = q;
            k++;
            q = p + l * k;
            l *= 10;
        }
        n -= p;
        int i = l / 90 + (n - 1) / k, j = (n - 1) % k;
        for (int ii = 1; ii < k - j; ii++)
            i /= 10;
        return i % 10;
    }
};