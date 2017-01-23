class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0)
            return vector<vector<int>>();
        vector<vector<int>> ans(n, vector<int>(n));

        ans[0][0] = 1;
        int i = 0, j = 0, k = 1, xMin = 0, yMin = 0, xMax = n - 1, yMax = n - 1;

        while (true) {
            while (j < xMax) ans[i][++j] = ++k;
            if (++yMin > yMax) break;

            while (i < yMax) ans[++i][j] = ++k;
            if (--xMax < xMin) break;

            while (j > xMin) ans[i][--j] = ++k;
            if (--yMax < yMin) break;

            while (i > yMin) ans[--i][j] = ++k;
            if (++xMin > xMax) break;
        }
        return ans;
    }
};