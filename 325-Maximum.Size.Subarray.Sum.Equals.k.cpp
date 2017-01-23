class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        unordered_map<int, int> m;
        m[0] = -1;

        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.find(sum - k) != m.end())
                maxLen = max(maxLen, i - m[sum - k]);
            if (m.find(sum) == m.end())
                m[sum] = i;
        }
        return maxLen;
    }
};