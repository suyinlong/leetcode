class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> text = {"r", "l", "d", "u"};
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int rows = maze.size(), cols = maze[0].size();
        vector<vector<int>> dis(rows, vector<int>(cols, -1));
        vector<vector<string>> path(rows, vector<string>(cols, ""));
        for (int i = 0; i < rows; i++)
            for (int j  = 0; j < cols; j++)
                if (maze[i][j] == 0)
                    dis[i][j] = INT_MAX;

        queue<vector<int>> q;
        dis[ball[0]][ball[1]] = 0;
        q.push({ball[0], ball[1]});

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
                    if (e[0] == hole[0] && e[1] == hole[1])
                        break;
                }
                int delta = abs(e[0] - d[0]) + abs(e[1] - d[1]);
                if (dis[d[0]][d[1]] + delta < dis[e[0]][e[1]]) {
                    dis[e[0]][e[1]] = dis[d[0]][d[1]] + delta;
                    path[e[0]][e[1]] = path[d[0]][d[1]] + text[i];
                    q.push(e);
                }
                else if (dis[d[0]][d[1]] + delta == dis[e[0]][e[1]] && path[d[0]][d[1]] + text[i] < path[e[0]][e[1]]) {
                    path[e[0]][e[1]] = path[d[0]][d[1]] + text[i];
                    q.push(e);
                }
            }
        }
        if (dis[hole[0]][hole[1]] == INT_MAX)
            return "impossible";
        return path[hole[0]][hole[1]];
    }
};