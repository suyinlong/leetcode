class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        int m = pattern.size(), n = str.size();
        if (m == 0 && n == 0) return true;
        if (m == 0) return false;
        vector<string> pMap(26, "");
        unordered_set<string> sMap;
        return match(pattern, str, 0, m, 0, n, pMap, sMap);
    }
private:
    bool match(string &pattern, string &str, int startP, int endP, int startS, int endS, vector<string> &pMap, unordered_set<string> &sMap) {
        if (startP == endP && startS == endS) return true;
        if (startP == endP || startS == endS) return false;

        char c = pattern[startP];
        if (pMap[c - 'a'].size() > 0) {
            string matched = pMap[c - 'a'];
            int len = matched.size();
            return startS + len <= endS && str.substr(startS, len) == matched && match(pattern, str, startP + 1, endP, startS + len, endS, pMap, sMap);
        }
        else {
            int endPoint = endS;
            for (int i = endP - 1; i > startP; i--)
                endPoint -= pMap[pattern[i] - 'a'].size();
            for (int i = startS; i < endPoint; i++) {
                string matched = str.substr(startS, i - startS + 1);
                if (sMap.count(matched)) continue;
                pMap[c - 'a'] = matched;
                sMap.insert(matched);
                if (match(pattern, str, startP + 1, endP, i + 1, endS, pMap, sMap)) return true;
                else {
                    pMap[c - 'a'] = "";
                    sMap.erase(matched);
                }
            }
        }
        return false;
    }
};