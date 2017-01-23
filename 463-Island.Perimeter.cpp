class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;

        int perimeter = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    if (i == 0 || grid[i-1][j] == 0) perimeter++;
                    if (i == m - 1 || grid[i+1][j] == 0) perimeter++;
                    if (j == 0 || grid[i][j-1] == 0) perimeter++;
                    if (j == n - 1 || grid[i][j+1] == 0) perimeter++;
                }

        return perimeter;
    }
};