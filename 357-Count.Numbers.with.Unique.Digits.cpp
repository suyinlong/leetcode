class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        int ans = 10;
        for (int k = 1; k < min(n, 10); k++) {
            int t = 9;
            for (int i = 0; i < k; i++)
                t *= (9 - i);
            ans += t;
        }
        return ans;
    }
};