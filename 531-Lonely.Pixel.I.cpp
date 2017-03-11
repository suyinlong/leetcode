class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = m == 0 ? 0 : picture[0].size();
        if (m == 0 || n == 0) return 0;
        vector<int> countRow(m, 0), countCol(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    countRow[i]++;
                    countCol[j]++;
                }
            }
        }
        int nRow = 0;
        for (int i = 0; i < m; i++) {
            if (countRow[i] == 1)
                nRow++;
        }
        int nCol = 0;
        for (int j = 0; j < n; j++) {
            if (countCol[j] == 1)
                nCol++;
        }
        return min(nRow, nCol);
    }
};