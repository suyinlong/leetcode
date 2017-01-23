class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if (nums[left] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(left);
        left = 0;
        right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        ans.push_back(left - 1);
        return ans;
    }
};