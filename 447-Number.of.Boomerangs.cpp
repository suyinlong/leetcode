class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.size() < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> md;
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    int x = points[i].first - points[j].first;
                    int y = points[i].second - points[j].second;
                    int dist = x * x + y * y;
                    if (md.find(dist) == md.end())
                        md[dist] = 0;
                    md[dist]++;
                }
            }
            for (auto it: md) {
                if (it.second >= 2)
                    ans += it.second * (it.second - 1);
            }
        }
        return ans;
    }
};