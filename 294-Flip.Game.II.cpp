class Solution {
public:
    bool canWin(string s) {
        if (s.size() < 2) return false;
        vector<bool> f(s.size() - 1, false);
        int cnt = 0;
        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] == '+' && s[i+1] == '+') {
                f[i] = true;
                cnt++;
            }
        unordered_map<string, bool> cache;
        return check(s, f, cnt, cache);
    }
private:
    bool check(string s, vector<bool> &f, int &cnt, unordered_map<string, bool> &cache) {
        if (cache.count(s))
            return cache[s];
        if (cnt == 0) {
            cache[s] = false;
            return cache[s];
        }
        for (int i = 0; i < f.size(); i++) {
            if (f[i]) {
                bool left = (i > 0) ? f[i-1] : false;
                bool right = (i < f.size() - 1) ? f[i+1] : false;
                s[i] = '-';
                s[i+1] = '-';
                f[i] = false;
                if (left) f[i-1] = false;
                if (right) f[i+1] = false;
                cnt--;
                if (left) cnt--;
                if (right) cnt--;
                bool r = check(s, f, cnt, cache);
                if (right) cnt++;
                if (left) cnt++;
                cnt++;
                if (right) f[i+1] = true;
                if (left) f[i-1] = true;
                f[i] = true;
                s[i+1] = '+';
                s[i] = '+';
                if (!r) {
                    cache[s] = true;
                    return cache[s];
                }
            }
        }
        cache[s] = false;
        return cache[s];
    }
};