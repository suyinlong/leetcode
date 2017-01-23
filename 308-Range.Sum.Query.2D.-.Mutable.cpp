class NumMatrix {
private:
    bool empty;
    int m, n;
    vector<vector<int>> _matrix;
    vector<vector<int>> BIT;

    int sumRegion(int row, int col) {
        int sum = 0;
        for (int i = row + 1; i > 0; i -= i & (-i))
            for (int j = col + 1; j > 0; j -= j & (-j))
                sum += BIT[i][j];
        return sum;
    }
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            empty = true;
            return;
        }
        m = matrix.size(); n = matrix[0].size();
        _matrix.resize(m, vector<int>(n, 0));
        BIT.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                update(i, j, matrix[i][j]);
    }

    void update(int row, int col, int val) {
        int diff = val - _matrix[row][col];
        for (int i = row + 1; i < m + 1; i += i & (-i))
            for (int j = col + 1; j < n + 1; j += j & (-j))
                BIT[i][j] += diff;
        _matrix[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumRegion(row2, col2) - sumRegion(row2, col1-1) - sumRegion(row1-1, col2) + sumRegion(row1-1, col1-1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);