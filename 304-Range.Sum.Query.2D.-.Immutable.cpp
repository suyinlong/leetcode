class NumMatrix {
private:
    bool empty;
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            empty = true;
            return;
        }
        empty = false;

        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int i = 1; i <= matrix.size(); i++)
            for(int j = 1; j <= matrix[0].size(); j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1] - dp[i-1][j-1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (empty)
            return 0;
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);