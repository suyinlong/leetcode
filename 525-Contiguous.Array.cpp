class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0, sum = 0;
        unordered_map<int, int> sumIdx;
        sumIdx[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) sum--;
            else sum++;
            if (sumIdx.find(sum) == sumIdx.end())
                sumIdx[sum] = i + 1;
            if (i + 1 - sumIdx[sum] > maxLen)
                maxLen = i + 1 - sumIdx[sum];
        }
        return maxLen;
    }
};