class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> map = {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
        vector<string> res;
        for (string s: words) {
            if (s.size() == 0) {
                res.push_back(s);
                continue;
            }
            int k = map[getIdx(s[0])];
            bool isRow = true;
            for (char c: s) {
                if (map[getIdx(c)] != k) {
                    isRow = false;
                    break;
                }
            }
            if (isRow)
                res.push_back(s);
        }
        return res;
    }
    int getIdx(char c) {
        return islower(c) ? (c - 'a') : (c - 'A');
    }
};