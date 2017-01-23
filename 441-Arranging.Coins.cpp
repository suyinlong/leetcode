class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1 + (long long)n * 8) - 1) / 2;
    }
};