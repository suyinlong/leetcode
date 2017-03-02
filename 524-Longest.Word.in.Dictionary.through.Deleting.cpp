class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (string w: d) {
            if (w.size() < res.size() || w.size() > s.size()) continue;
            int i = 0, j = 0;
            while (j < w.size()) {
                while (i < s.size() && s[i] != w[j]) i++;
                if (i == s.size()) break;
                i++;
                j++;
            }
            if (j == w.size() && (w.size() > res.size() || (w.size() == res.size() && w < res)))
                res = w;
        }
        return res;
    }
};