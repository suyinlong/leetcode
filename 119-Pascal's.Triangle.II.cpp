class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        ans[rowIndex] = 1;
        if (rowIndex == 0) return ans;

        ans[rowIndex] = 1;
        for (int i = 1; i <= rowIndex; i++)
            for (int j = rowIndex - i; j < rowIndex; j++)
                ans[j] += ans[j+1];
        return ans;
    }
};