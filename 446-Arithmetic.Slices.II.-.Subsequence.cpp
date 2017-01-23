class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;

        int res = 0;
        vector<unordered_map<int, int>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((long long)A[i] - (long long)A[j] > INT_MAX || (long long)A[i] - (long long)A[j] < INT_MIN) continue;
                int diff = A[i] - A[j];
                dp[i][diff] += 1;
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        return res;
    }
};