class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        if (s.size() < 2) return result;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string n(s);
                n[i] = '-';
                n[i+1] = '-';
                result.push_back(n);
            }
        }
        return result;
    }
};