class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0)
            return false;
        int curM = nums[0];
        for (int i = 0; i < nums.size() && i <= curM; i++) {
            curM = max(curM, i + nums[i]);
            if (curM >= nums.size() - 1)
                return true;
        }
        return false;
    }
};