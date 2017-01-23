class Solution {
public:
    bool isEqual(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
    void reCalc(string &s, int k, int m, vector<int> &count) {
        for (int i = 0; i < 26; i++)
            count[i] = 0;
        for (int i = 0; i < m; i++)
            count[s[k+i] - 'a']++;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int m = p.length();
        if (s.length() < m)
            return result;

        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c: p)
            pCount[c - 'a'] ++;

        int k = 0;
        reCalc(s, k, m, sCount);

        while (k <= s.length() - m) {
            if (isEqual(pCount, sCount)) {
                result.push_back(k);
            }
            if (k == s.length() - m)
                break;
            sCount[s[k] - 'a'] --;
            sCount[s[k+m] - 'a'] ++;
            k++;
        }

        return result;
    }
};