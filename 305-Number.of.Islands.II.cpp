class Solution {
private:
    vector<int> id;

    int findRoot(int i) {
        if (i != id[i])
            id[i] = findRoot(id[i]);
        return id[i];
    }
    bool unite(int a, int b) {
        int p = findRoot(a), q = findRoot(b);
        if (p == q) return false;
        if (p != q) {
            if (p < q) id[q] = p;
            else id[p] = q;
        }
        return true;
    }
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        id.resize(m * n);
        for (int i = 0; i < m * n; i++)
            id[i] = i;
        vector<int> ans;
        vector<vector<bool>> map(m, vector<bool>(n, false));
        int num = 0;
        for (int i = 0; i < positions.size(); i++) {
            int x = positions[i].first, y = positions[i].second;
            if (map[x][y]) {
                ans.push_back(num);
                continue;
            }
            map[x][y] = true;
            num++;
            if (x > 0 && map[x-1][y] && unite(n * x + y, n * (x - 1) + y)) num--;
            if (x < m - 1 && map[x+1][y] && unite(n * x + y, n * (x + 1) + y)) num--;
            if (y > 0 && map[x][y-1] && unite(n * x + y, n * x + y - 1)) num--;
            if (y < n - 1 && map[x][y+1] && unite(n * x + y, n * x + y + 1)) num--;
            ans.push_back(num);
        }
        return ans;
    }
};