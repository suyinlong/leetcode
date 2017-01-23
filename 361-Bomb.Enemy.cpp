class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        if (m == 0 || n == 0) return 0;
        int res = 0, rowKill = 0;
        vector<int> colKill(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 || grid[i][j-1] == 'W') {
                    // calc rowKill
                    rowKill = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++)
                        rowKill += grid[i][k] == 'E';
                }
                if (i == 0 || grid[i-1][j] == 'W') {
                    // calc colKill[j]
                    colKill[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++)
                        colKill[j] += grid[k][j] == 'E';
                }
                if (grid[i][j] == '0')
                    res = max(res, rowKill + colKill[j]);
            }
        }
        return res;
    }
};