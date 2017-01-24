class Solution {
public:
    int findKthNumber(int n, int k) {
        int c = 1;
        k -= 1;
        while (k > 0) {
            int step = steps(n, c, c + 1);
            if (step <= k) {
                c += 1;
                k -= step;
            }
            else {
                c *= 10;
                k -= 1;
            }
        }
        return c;
    }
private:
    int steps(long n, long n1, long n2) {
        int res = 0;
        while (n1 <= n) {
            res += min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return res;
    }
};