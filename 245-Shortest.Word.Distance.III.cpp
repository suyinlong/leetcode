class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int i = -1, j = -1, ans = INT_MAX;
        for (int k = 0; k < words.size(); k++) {
            if (words[k] == word1 && words[k] == word2) {
                i = j;
                j = k;
            }
            if (word1 != word2 && words[k] == word1)
                i = k;
            if (word1 != word2 && words[k] == word2)
                j = k;
            if (i >= 0 && j >= 0 && (words[k] == word1 || words[k] == word2) && abs(i-j) < ans)
                ans = abs(i-j);
        }
        return ans;
    }
};