class Vector2D {
private:
    int x, y;
    vector<vector<int>> v2d;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v2d = vec2d;
        x = 0; y = 0;
        if (x == v2d.size() || y < v2d[0].size())
            return;
        while (x < v2d.size() && y == v2d[x].size())
            x++;
    }

    int next() {
        int ans = v2d[x][y];
        y++;
        if (y == v2d[x].size()) {
            x++; y = 0;
            if (x == v2d.size() || y < v2d[x].size())
                return ans;
            while (x < v2d.size() && y == v2d[x].size())
                x++;
        }
        return ans;
    }

    bool hasNext() {
        return (x < v2d.size() && y < v2d[x].size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */