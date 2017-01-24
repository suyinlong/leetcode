class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        vector<pair<char, char>> pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int count = 0;
        for (int len = low.size(); len <= high.size(); len++) {
            string num(len, '0');
            dfs(low, high, num, 0, len - 1, count, pairs);
        }
        return count;
    }
private:
    void dfs(string &low, string &high, string &num, int left, int right, int &count, vector<pair<char, char>> &pairs) {
        if (left > right) {
            if (num.size() == low.size() && num < low) return;
            if (num.size() == high.size() && num > high) return;
            count++;
            return;
        }
        for (auto p: pairs) {
            num[left] = p.first;
            num[right] = p.second;
            if (num.size() != 1 && num[0] == '0') continue;
            if (left < right || (left == right && p.first == p.second))
                dfs(low, high, num, left + 1, right - 1, count, pairs);
        }
    }
};