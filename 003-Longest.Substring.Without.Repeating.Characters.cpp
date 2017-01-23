class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> idx(256, -1);
        int m = 0, i = 0, j = 0;

        for (j = 0; j < s.length(); j++) {
            if (idx[s[j]] != -1) {
                int k = idx[s[j]] + 1;
                for ( ; i < k; i++)
                    idx[s[i]] = -1;
            }
            idx[s[j]] = j;
            m = max(m, j - i + 1);
        }
        return m;
    }
};