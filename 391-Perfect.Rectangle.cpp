class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<int, unordered_map<int, char>> corners;
        int down = INT_MAX, up = INT_MIN, left = INT_MAX, right = INT_MIN;

        for (auto r: rectangles) {
            down = min(down, r[1]);
            left = min(left, r[0]);
            right = max(right, r[2]);
            up = max(up, r[3]);

            char mask = 0;
            mask = corners[r[0]][r[1]];
            if (mask & 1) return false;
            corners[r[0]][r[1]] |= 1;

            mask = corners[r[2]][r[1]];
            if (mask & 2) return false;
            corners[r[2]][r[1]] |= 2;

            mask = corners[r[2]][r[3]];
            if (mask & 4) return false;
            corners[r[2]][r[3]] |= 4;

            mask = corners[r[0]][r[3]];
            if (mask & 8) return false;
            corners[r[0]][r[3]] |= 8;
        }
        for (auto itx = corners.begin(); itx != corners.end(); itx++) {
            int x = itx->first;
            for (auto ity = itx->second.begin(); ity != itx->second.end(); ity++) {
                int y = ity->first;
                char mask = ity->second;
                if ((x == left || x == right) && (y == up || y == down)) {
                    if (mask != 1 && mask != 2 && mask != 4 && mask != 8)
                        return false;
                }
                else if (mask != 3 && mask != 6 && mask != 9 && mask != 12 && mask != 15)
                    return false;

            }
        }

        return true;
    }
};