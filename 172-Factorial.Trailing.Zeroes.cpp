class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long p = 5, nn = n;
        while (nn >= p) {
            ans += (nn / p);
            p *= 5;
        }
        return ans;
    }
};