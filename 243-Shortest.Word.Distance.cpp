class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX, i = -1, j = -1;
        for (int k = 0; k < words.size(); k++) {
            if (words[k] == word1)
                i = k;
            if (words[k] == word2)
                j = k;
            if (i >= 0 && j >= 0 && (words[k] == word1 || words[k] == word2) && abs(i - j) < ans)
                ans = abs(i-j);
        }
        return ans;
    }
};