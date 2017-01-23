class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if (nums.size() == 0)
            return ans;

        sort(nums.begin(), nums.end());
        vector<int> len(nums.size(), 1);
        vector<int> pre(nums.size(), -1);

        int maxIndex = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && 1 + len[j] > len[i]) {
                    len[i] = 1 + len[j];
                    pre[i] = j;
                }

            }
            if (maxIndex == INT_MIN || len[i] > len[maxIndex])
                maxIndex = i;
        }

        while (maxIndex != -1) {
            ans.push_back(nums[maxIndex]);
            maxIndex = pre[maxIndex];
        }
        return ans;
    }
};