class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = m > 0 ? maze[0].size() : 0;
        if (m == 0 || n == 0) return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return helper(maze, start, destination, visited);
    }
    bool helper(vector<vector<int>> &maze, vector<int> &s, vector<int> &e, vector<vector<bool>> &visited) {
        if (s == e) return true;
        if (visited[s[0]][s[1]]) return false;
        visited[s[0]][s[1]] = true;
        for (int i = 0; i < 4; i++) {
            vector<int> d = s;
            while (d[0] + dirs[i][0] >= 0 && d[0] + dirs[i][0] < maze.size()
                && d[1] + dirs[i][1] >= 0 && d[1] + dirs[i][1] < maze[0].size()
                && maze[d[0] + dirs[i][0]][d[1] + dirs[i][1]] == 0) {
                d[0] += dirs[i][0];
                d[1] += dirs[i][1];
            }
            if (d == e || helper(maze, d, e, visited)) return true;
        }
        return false;
    }
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};