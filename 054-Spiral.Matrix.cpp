class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        if (n == 0) return ans;

        ans.push_back(matrix[0][0]);
        int i = 0, j = 0, xMin = 0, yMin = 0, xMax = n - 1, yMax = m - 1;
        while (true) {
            while (j < xMax) ans.push_back(matrix[i][++j]);
            if (++yMin > yMax) break;

            while (i < yMax) ans.push_back(matrix[++i][j]);
            if (--xMax < xMin) break;

            while (j > xMin) ans.push_back(matrix[i][--j]);
            if (--yMax < yMin) break;

            while (i > yMin) ans.push_back(matrix[--i][j]);
            if (++xMin > xMax) break;
        }
        return ans;
    }
};