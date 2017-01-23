class Solution {
public:
    int gcd(int x, int y) {
        if (x < y) swap(x, y);
        while (y) {
            x %= y;
            swap(x, y);
        }
        return x;
    }
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z)
            return false;
        if (x + y == 0)
            return (z == 0);
        return (z % gcd(x, y) == 0);
    }
};