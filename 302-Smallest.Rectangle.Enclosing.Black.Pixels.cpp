class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left = searchColumns(image, 0, y, 0, m, true);
        int right = searchColumns(image, y + 1, n, 0, m, false);
        int top = searchRows(image, 0, x, left, right, true);
        int bottom = searchRows(image, x + 1, m, left, right, false);
        return (right - left) * (bottom - top);
    }
    int searchColumns(vector<vector<char>> &image, int i, int j, int top, int bottom, bool flag) {
        while (i != j) {
            int k = top, mid = i + (j - i) / 2;
            while (k < bottom && image[k][mid] == '0') k++;
            if (k < bottom == flag)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
    int searchRows(vector<vector<char>> &image, int i, int j, int left, int right, bool flag) {
        while (i != j) {
            int k = left, mid = i + (j - i) / 2;
            while (k < right && image[mid][k] == '0') k++;
            if (k < right == flag)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
};