class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                major = nums[i];
                count = 1;
            }
            else
                count += (major == nums[i]) ? 1 : -1;
        }
        return major;
    }
};