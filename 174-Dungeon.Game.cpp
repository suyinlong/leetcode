class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0)
            return 0;
        int m = dungeon.size(), n = dungeon[0].size();

        dungeon[m-1][n-1] = (dungeon[m-1][n-1] > 0) ? 1 : 1 - dungeon[m-1][n-1];
        for (int i = m - 2; i >= 0; i--)
            dungeon[i][n-1] = max(dungeon[i+1][n-1] - dungeon[i][n-1], 1);
        for (int j = n - 2; j >= 0; j--)
            dungeon[m-1][j] = max(dungeon[m-1][j+1] - dungeon[m-1][j], 1);

        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
                dungeon[i][j] = max(min(dungeon[i+1][j], dungeon[i][j+1]) - dungeon[i][j], 1);

        return dungeon[0][0];
    }
};