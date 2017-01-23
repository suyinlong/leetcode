class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if (word == abbr)
            return true;
        int p = 0, q = 0;
        while (p < word.size() && q < abbr.size()) {
            if (abbr[q] >= 'a' && abbr[q] <= 'z') {
                if (word[p] != abbr[q]) return false;
                p++; q++;
            }
            else {
                if (abbr[q] == '0') return false;
                int qq = q;
                while (abbr[qq] >= '0' && abbr[qq] <= '9' && qq < abbr.size()) qq++;
                int len = stoi(abbr.substr(q, qq-q));
                p += len; q = qq;
            }
        }
        return (p == word.size()) && (q == abbr.size());
    }
};