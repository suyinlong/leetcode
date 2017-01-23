class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size(), num = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < rows; i++) {
            int start = num % n;
            if (dp[start])
                num += dp[start];
            else {
                int cnt = 0, len = 0;
                for (int j = start; len < cols; j = (j+1) % n, cnt++) {
                    if (len + sentence[j].size() > cols) break;
                    len += sentence[j].size() + 1;
                }
                num += cnt;
                dp[start] = cnt;
            }
        }
        return num / n;
    }
};