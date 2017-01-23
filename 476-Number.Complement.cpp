class Solution {
public:
    int findComplement(int num) {
        int k = num, mask = 1;
        while (k != 1) {
            k >>= 1;
            mask = (mask << 1) + 1;
        }
        return (~num) & mask;
    }
};