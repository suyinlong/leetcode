class Solution {
public:
    int hammingDistance(int x, int y) {
        int k = x ^ y, r = 0;
        while (k) {
            k = k & (k-1);
            r++;
        }
        return r;
    }
};