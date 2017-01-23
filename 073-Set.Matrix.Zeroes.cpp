class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool clrRow0 = false, clrCol0 = false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) {
                    if (i == 0) clrRow0 = true;
                    if (j == 0) clrCol0 = true;
                    if (i > 0 && j > 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
        for (int j = 1; j < n; j++)
            if (matrix[0][j] == 0)
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
        for (int i = 1; i < m; i++)
            if (matrix[i][0] == 0)
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
        if (clrRow0)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if (clrCol0)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;

    }
};