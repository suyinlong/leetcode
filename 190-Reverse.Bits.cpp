class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t t, ans = 0;
        for (int i = 31; i >= 0; i--) {
            t = n << i;
            t >>= 31;
            ans <<= 1;
            ans |= t;
        }
        return ans;
    }
};