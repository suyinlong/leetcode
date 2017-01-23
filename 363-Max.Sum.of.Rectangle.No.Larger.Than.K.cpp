class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        if (m == 0 || n == 0) return 0;

        int maxSum = INT_MIN;
        for (int l = 0; l < n; l++) {
            vector<int> sums(m, 0);
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++)
                    sums[i] += matrix[i][r];
                set<int> accuSum;
                accuSum.insert(0);
                int curSum = 0;
                for (int accu: sums) {
                    curSum += accu;
                    auto it = accuSum.lower_bound(curSum - k);
                    if (it != accuSum.end()) maxSum = max(maxSum, curSum - *it);
                    accuSum.insert(curSum);
                }

            }
        }
        return maxSum;
    }
};