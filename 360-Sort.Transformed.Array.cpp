class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ans(n, 0);
        if (n == 0)
            return ans;
        if (a == 0)
            for (int i = 0; i < n; i++)
                ans[i] = b * nums[i] + c;
        else {
            double axis = -(double)b/(double)a/2.0;
            int i = 0, j = n - 1, p = 0, x;
            while (i <= j) {
                if (fabs((double)nums[i] - axis) < fabs((double)nums[j] - axis)) {
                    x = nums[j]; j--;
                }
                else {
                    x = nums[i]; i++;
                }
                ans[p++] = a * x * x + b * x + c;
            }
        }

        if (a > 0 || (a == 0 && b < 0)) reverse(ans.begin(), ans.end());

        return ans;


    }
};