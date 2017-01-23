class Solution {
private:
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &r, vector<vector<bool>> &v) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || v[i][j])
            return 0;
        if (r[i][j] != -1)
            return r[i][j];
        v[i][j] = true;
        int k = 0;
        if (i > 0 && matrix[i-1][j] > matrix[i][j])
            k = max(k, dfs(matrix, i-1, j, r, v));
        if (i < matrix.size() - 1 && matrix[i+1][j] > matrix[i][j])
            k = max(k, dfs(matrix, i+1, j, r, v));
        if (j > 0 && matrix[i][j-1] > matrix[i][j])
            k = max(k, dfs(matrix, i, j-1, r, v));
        if (j < matrix[0].size() - 1 && matrix[i][j+1] > matrix[i][j])
            k = max(k, dfs(matrix, i, j+1, r, v));
        v[i][j] = false;
        r[i][j] = 1 + k;
        return r[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<vector<int>> r(matrix.size(), vector<int>(matrix[0].size(), -1));
        vector<vector<bool>> v(matrix.size(), vector<bool>(matrix[0].size(), false));
        int m = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++) {
                dfs(matrix, i, j, r, v);
                m = max(m, r[i][j]);
            }
        return m;
    }
};