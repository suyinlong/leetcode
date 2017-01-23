class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int l = 0, r = min(46341, x);
        while (r - l > 1) {
            int m = l + ((r - l) >> 1);
            if (m * m > x)
                r = m;
            else
                l = m;
        }
        return l;
    }
};