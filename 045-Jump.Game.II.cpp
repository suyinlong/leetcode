class Solution {
public:
    int jump(vector<int>& nums) {
        int curMaxStep = 0, maxLength = 0, curMaxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > curMaxLength) break;
            curMaxLength = max(curMaxLength, i + nums[i]);
            if (i == nums.size() - 1)
                return curMaxStep;
            if (i == maxLength) {
                maxLength = curMaxLength;
                curMaxStep++;
            }
        }
        return curMaxStep;
    }
};