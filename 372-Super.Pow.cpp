class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int k = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, k) % base;
    }
private:
    const int base = 1337;
    int powmod(int a, int k) {
        a %= base;
        int res = 1;
        for (int i = 0; i < k; i++)
            res = (res * a) % base;
        return res;
    }
};