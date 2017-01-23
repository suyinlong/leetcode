class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int i = 0, maxCount = 0, n = s.size(), maxSize = 0;

        for (int j = 0; j < n; j++) {
            count[s[j] - 'A'] ++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            while (j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
                maxCount = 0;
                for (int k = 0; k < 26; k++)
                    maxCount = max(maxCount, count[k]);
            }
            maxSize = max(maxSize, j - i + 1);
        }
        return maxSize;
    }
};