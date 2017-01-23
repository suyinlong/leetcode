class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int xMin = INT_MAX, xMax = INT_MIN;
        unordered_map<int, unordered_set<int>> xMap;
        for (int i = 0; i < points.size(); i++) {
            xMin = min(xMin, points[i].first);
            xMax = max(xMax, points[i].first);
            xMap[points[i].first].insert(points[i].second);
        }
        double line = ((double)xMax + (double)xMin) / 2;
        for (auto it = xMap.begin(); it != xMap.end(); it++) {
            int x1 = it->first;
            int x2 = line * 2 - x1;
            for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
                int y1 = *jt;
                if (xMap[x2].find(y1) == xMap[x2].end())
                    return false;
            }
        }
        return true;
    }
};