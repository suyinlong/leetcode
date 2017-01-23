class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int ans = 0, arrow = INT_MIN;
        sort(points.begin(), points.end(), [](pair<int,int> a, pair<int,int> b){return a.second<b.second;});
        for (int i = 0; i < points.size(); i++) {
            if (arrow != INT_MIN && points[i].first <= arrow)
                continue;
            arrow = points[i].second;
            ans++;
        }
        return ans;

    }
};