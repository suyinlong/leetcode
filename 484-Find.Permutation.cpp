class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == 'I') {
                int len = res.size();
                for (int j = i + 1; j > len; j--) {
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};