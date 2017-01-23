class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if (words.size() == 0)
            return result;

        int p = 0, q = 0, count = 0;
        while (q < words.size()) {
            if (count == 0) {
                count += words[q].length();
                q++;
            }
            else if (count + words[q].length() + 1 <= maxWidth) {
                count += words[q].length() + 1;
                q++;
            }
            else {
                result.push_back(formatWords(words, p, q, maxWidth));
                p = q;
                count = 0;
            }
        }
        result.push_back(formatWords(words, p, q, maxWidth, false));
        return result;
    }
    string formatWords(vector<string> &words, int p, int q, int L, bool justify = true) {
        string s = "";
        int sLength = L;
        for (int i = p; i < q; i++) {
            sLength -= words[i].length();
        }
        for (int i = p; i < q; i++) {
            if (i > p) {
                if (justify) {
                    int c = (sLength-1)/(q-i) + 1;
                    sLength -= c;
                    while (c > 0) {
                        s += ' ';
                        c--;
                    }
                }
                else s += ' ';
            }
            s += words[i];
        }
        if (q - p == 1) {
            while (sLength > 0) {
                s += ' ';
                sLength--;
            }
        }
        if (!justify) {
            while (s.length() < L) s += ' ';
        }

        return s;
    }
};