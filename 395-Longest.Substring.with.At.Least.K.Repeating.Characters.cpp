class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, 0, s.length(), k);
    }
    int longestSubstring(string s, int start, int end, int k) {
        if (end - start < k)
            return 0;
        vector<int> cnt(26, 0);
        for (int i = start; i < end; i++)
            cnt[s[i]-'a'] ++;
        for (int i = start; i < end; i++)
            if (cnt[s[i]-'a'] < k)
                return max(longestSubstring(s, start, i, k), longestSubstring(s, i + 1, end, k));
        return end - start;
    }
};