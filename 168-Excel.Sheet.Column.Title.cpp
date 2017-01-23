class Solution {
public:
    string convertToTitle(int n) {
        string r;
        while (n) {
            int t = (n-1) % 26;
            char c = 'A' + t;
            r.push_back(c);
            n = (n-1) / 26;
        }
        reverse(r.begin(), r.end());
        return r;
    }
};