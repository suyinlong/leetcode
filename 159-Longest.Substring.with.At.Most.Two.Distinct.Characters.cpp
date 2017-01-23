class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length() == 0)
            return 0;
        vector<int> winCnt(256, 0);
        int n = s.length(), cnt = 0, i = 0, ans = 0;
        for (int j = 0; j < n; j++) {
            winCnt[s[j]]++;
            if (winCnt[s[j]] == 1) cnt++;
            while (cnt > 2) {
                winCnt[s[i]] --;
                if (winCnt[s[i]] == 0) cnt--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};