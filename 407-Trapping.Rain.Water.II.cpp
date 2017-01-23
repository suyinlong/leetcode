class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            visited[i][0] = true;
            visited[i][n-1] = true;
            pq.push(make_pair(heightMap[i][0], i * n));
            pq.push(make_pair(heightMap[i][n-1], i * n + n - 1));
        }
        for (int j = 1; j < n - 1; j++) {
            visited[0][j] = true;
            visited[m-1][j] = true;
            pq.push(make_pair(heightMap[0][j], j));
            pq.push(make_pair(heightMap[m-1][j], (m - 1) * n + j));
        }

        int ans = 0;
        while (!pq.empty()) {
            int h = pq.top().first, row = pq.top().second / n, col = pq.top().second % n;
            pq.pop();
            for (int k = 0; k < 4; k++) {
                int row2 = row + dir[k][0], col2 = col + dir[k][1];
                if (row2 < 0 || row2 >= m || col2 < 0 || col2 >= n || visited[row2][col2])
                    continue;
                visited[row2][col2] = true;
                ans += max(0, h - heightMap[row2][col2]);
                pq.push(make_pair(max(h, heightMap[row2][col2]), row2 * n + col2));
            }
        }
        return ans;
    }
};