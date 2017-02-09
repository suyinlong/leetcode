class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size(), cols = maze[0].size();
        vector<vector<int>> dis(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; i++)
            for (int j  = 0; j < cols; j++)
                if (maze[i][j] == 0)
                    dis[i][j] = INT_MAX;
        queue<vector<int>> q;
        dis[start[0]][start[1]] = 0;
        q.push({start[0], start[1]});

        while (!q.empty()) {
            vector<int> d = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                vector<int> e = d;
                while (e[0] + dirs[i][0] >= 0 && e[0] + dirs[i][0] < rows
                && e[1] + dirs[i][1] >= 0 && e[1] + dirs[i][1] < cols
                && maze[e[0] + dirs[i][0]][e[1] + dirs[i][1]] == 0) {
                    e[0] += dirs[i][0];
                    e[1] += dirs[i][1];
                }
                int delta = abs(e[0] - d[0]) + abs(e[1] - d[1]);
                if (dis[d[0]][d[1]] + delta < dis[e[0]][e[1]]) {
                    dis[e[0]][e[1]] = dis[d[0]][d[1]] + delta;
                    q.push(e);
                }
            }
        }
        if (dis[destination[0]][destination[1]] == INT_MAX)
            return -1;
        return dis[destination[0]][destination[1]];
    }
};