class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), count = 0;
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        vector<int> x, y;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    x.push_back(i);
                    y.push_back(j);
                    count ++;
                }
        int mid = count >> 1;
        nth_element(x.begin(), x.begin() + mid, x.end());
        nth_element(y.begin(), y.begin() + mid, y.end());
        int dist = 0;
        for (int i = 0; i < count; i++) {
            dist += abs(x[i] - x[mid]);
            dist += abs(y[i] - y[mid]);
        }
        return dist;
    }
};