class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        if (m > n)
            return uniquePaths(n, m);
        long long ans = 1;
        for (int i = n; i <= m + n - 2; i++)
            ans *= i;
        for (int i = 2; i <= m - 1; i++)
            ans /= i;
        return ans;
    }
};