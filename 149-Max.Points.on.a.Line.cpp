/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<double, int> line;
        int maxNum = 0;
        for (int i = 0; i < points.size(); i++) {
            line.clear();
            int dup = 1;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    dup++;
                    continue;
                }
                double k = std::numeric_limits<double>::infinity();
                if (points[i].x != points[j].x)
                    k = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x);
                line[k]++;
            }
            maxNum = max(dup, maxNum);
            for (auto it = line.begin(); it != line.end(); it++)
                maxNum = max(maxNum, it->second + dup);
        }
        return maxNum;
    }
};