class Solution {
public:
    int reverse(int x) {
        int sign = (x >= 0) ? 1 : -1;
        int ans = 0;
        while (x != 0) {
            // INT_MAX = 2,147,483,647
            if (ans > 214748364 || (ans == 214748364 && (x % 10) > 7))
                return 0;
            ans *= 10;
            ans += abs(x % 10);
            x /= 10;
        }
        return sign * ans;
    }
};