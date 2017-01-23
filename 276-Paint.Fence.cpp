class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        int a = k, b = 0, x, y;
        for (int i = 2; i <= n; i++) {
            x = (k - 1) * (a + b);
            y = a;
            a = x;
            b = y;
        }
        return a + b;
    }
};