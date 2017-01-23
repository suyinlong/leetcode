class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long long prev = 0, cur;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> A;
            for (int j = 1; j < 3; j++)
                A.push_back({points[(i+j)%n][0] - points[i][0], points[(i+j)%n][1] - points[i][1]});
            if ((cur = det2(A)) * prev < 0)
                return false;
            else if (cur != 0)
                prev = cur;
        }
        return true;
    }
    long long det2(vector<vector<int>> &A) {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
};