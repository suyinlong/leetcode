// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int a = guess(m);
            if (a == 0)
                return m;
            else if (a > 0)
                l = m + 1;
            else if (a < 0)
                r = m - 1;
        }
        return 0;
    }
};