class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int pos = 2;
        while (s.size() < n)
            s += string(s[pos++] - '0', s.back() ^ 3);
        return count(s.begin(), s.begin() + n, '1');
    }
};