class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> tri;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i)
                    row.push_back(1);
                else
                    row.push_back(tri.back()[j-1] + tri.back()[j]);
            }
            tri.push_back(row);
        }

        return tri;
    }
};