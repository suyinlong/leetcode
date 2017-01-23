class Solution {
public:
    void dfs(int p, int n, int num, vector<string> &result) {
        if (p == 10) {
            int h = (n & 0x3C0) >> 6;
            int m = (n & 0x03F);
            if (h <= 11 && m <= 59) {
                string s = to_string(h);
                s += ":";
                if (m < 10)
                    s += "0";
                s += to_string(m);
                result.push_back(s);
            }
            return;
        }
        if (num == 0)
            dfs(p+1, n << 1, num, result);
        else if (num == 10 - p)
            dfs(p+1, (n << 1) + 1, num-1, result);
        else {
            dfs(p+1, n << 1, num, result);
            dfs(p+1, (n << 1) + 1, num-1, result);
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        dfs(0, 0, num, result);
        return result;
    }
};