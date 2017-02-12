class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        int rows = matrix.size(), cols = rows == 0 ? 0 : matrix[0].size();
        if (rows == 0 || cols == 0) return order;

        for (int i = 0; i < rows + cols - 1; i++) {
            if (i % 2 == 0) {
                int x = min(i, rows - 1), y = i < rows ? 0 : i - rows + 1;
                while (x >= 0 && x < rows && y >= 0 && y < cols) {
                    order.push_back(matrix[x][y]);
                    x--; y++;
                }
            }
            else {
                int x = i < cols ? 0 : i - cols + 1, y = min(i, cols - 1);
                while (x >= 0 && x < rows && y >= 0 && y < cols) {
                    order.push_back(matrix[x][y]);
                    x++; y--;
                }
            }
        }
        return order;
    }
};