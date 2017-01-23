class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<uint32_t, bool> cache;
        return check(desiredTotal, 0, maxChoosableInteger, cache);
    }
private:
    bool check(int d, int mask, int m, unordered_map<uint32_t, bool> &cache) {
        if (cache.count(mask))
            return cache[mask];
        bool r;
        for (int i = m; i > 0; i--) {
            int bit = 1 << i;
            if ((mask & bit) == 0) {
                if (i >= d || !check(d - i, mask | bit, m, cache)) {
                    cache[mask] = true;
                    return true;
                }
            }
        }
        cache[mask] = false;
        return false;
    }
};