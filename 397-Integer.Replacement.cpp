class Solution {
public:
    int integerReplacement(int n) {
        int r = 0;
        if (n == INT_MAX)
            return 32;
        while (n != 1) {
            if ((n & 1) == 0)
                n >>= 1;
            else if (n == 3) {
                n = 1;
                r++;
            }
            else if ((n & 3) == 3)
                n += 1;
            else
                n -= 1;
            r++;
        }
        return r;
    }
};