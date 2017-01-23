class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a = A.size(), b = A[0].size(), c = B[0].size();
        vector<vector<pair<int, int>>> sA(a);

        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if (A[i][j] != 0)
                    sA[i].push_back(make_pair(j, A[i][j]));
        vector<vector<int>> C(a, vector<int>(c, 0));
        for (int i = 0; i < a; i++)
            for (int j = 0; j < sA[i].size(); j++) {
                int col = sA[i][j].first, val = sA[i][j].second;
                for (int k = 0; k < c; k++)
                    C[i][k] += val * B[col][k];
            }
        return C;
    }
};