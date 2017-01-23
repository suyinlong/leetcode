class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0 || matrix[0].size() != n)
            return;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};