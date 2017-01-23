class Solution {
public:
    void dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &visited, int h, int flag, vector<pair<int, int>> &result) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] < h || (visited[i][j] & flag) == flag)
            return;
        visited[i][j] |= flag;
        if (visited[i][j] == 3)
            result.push_back(pair<int, int>(i, j));
        dfs(matrix, i-1, j, visited, matrix[i][j], flag, result);
        dfs(matrix, i+1, j, visited, matrix[i][j], flag, result);
        dfs(matrix, i, j-1, visited, matrix[i][j], flag, result);
        dfs(matrix, i, j+1, visited, matrix[i][j], flag, result);
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix.size(); i++) {
            dfs(matrix, i, 0, visited, INT_MIN, 0x01, result);
            dfs(matrix, i, matrix[0].size() - 1, visited, INT_MIN, 0x02, result);
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            dfs(matrix, 0, j, visited, INT_MIN, 0x01, result);
            dfs(matrix, matrix.size() - 1, j, visited, INT_MIN, 0x02, result);
        }
        return result;
    }
};