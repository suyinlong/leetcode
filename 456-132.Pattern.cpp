class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int ak = INT_MIN;
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < ak) return true;
            while (!stk.empty() && nums[i] > stk.top()) {
                ak = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};