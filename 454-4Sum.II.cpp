class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> twoSum;

        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++) {
                int k = A[i] + B[j];
                twoSum[k]++;
            }
        int ans = 0;
        for (int i = 0; i < C.size(); i++)
            for (int j = 0; j < D.size(); j++) {
                int k = C[i] + D[j];
                auto it = twoSum.find(-k);
                if (it != twoSum.end())
                    ans += it->second;
            }

        return ans;
    }
};