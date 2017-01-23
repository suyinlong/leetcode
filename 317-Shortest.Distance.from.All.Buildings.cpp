class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return -1;
        int n = grid[0].size();
        if (n == 0) return -1;

        auto total = grid;
        int empty = 0, minDist = -1;
        vector<int> dir = {0, 1, 0, -1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minDist = -1;
                    auto dist = grid;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = p.first + dir[k];
                            int y = p.second + dir[k+1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == empty) {
                                grid[x][y] --;
                                dist[x][y] = dist[p.first][p.second] + 1;
                                total[x][y] += dist[x][y] - 1;
                                q.emplace(x, y);
                                if (minDist < 0 || minDist > total[x][y])
                                    minDist = total[x][y];
                            }
                        }
                    }
                    empty--;
                }
            }
        }
        return minDist;
    }
};