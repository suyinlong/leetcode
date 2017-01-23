class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0)
            return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> qRoom;
        queue<int> qDist;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0) {
                    qRoom.push(make_pair(i, j));
                    qDist.push(0);
                }
        while (!qRoom.empty()) {
            int x = qRoom.front().first, y = qRoom.front().second, d = qDist.front() + 1;
            qRoom.pop();
            qDist.pop();
            if (x > 0 && rooms[x-1][y] == INT_MAX) {
                rooms[x-1][y] = d;
                qRoom.push(make_pair(x-1, y));
                qDist.push(d);
            }
            if (x < m - 1 && rooms[x+1][y] == INT_MAX) {
                rooms[x+1][y] = d;
                qRoom.push(make_pair(x+1, y));
                qDist.push(d);
            }
            if (y > 0 && rooms[x][y-1] == INT_MAX) {
                rooms[x][y-1] = d;
                qRoom.push(make_pair(x, y-1));
                qDist.push(d);
            }
            if (y < n - 1 && rooms[x][y+1] == INT_MAX) {
                rooms[x][y+1] = d;
                qRoom.push(make_pair(x, y+1));
                qDist.push(d);
            }


        }
    }
};