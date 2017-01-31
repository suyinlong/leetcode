class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area);
        while (area % W != 0) W--;
        vector<int> res = {area / W, W};
        return res;
    }
};