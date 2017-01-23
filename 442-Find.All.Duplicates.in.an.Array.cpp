class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        if (nums.size() == 0 || nums.size() == 1)
            return ans;
        int i = 0;
        while (i < nums.size()) {
            int k = nums[i];
            if (k == (i + 1) || k == 0) {
                i++;
                continue;
            }
            while (k != (i + 1)) {
                if (nums[k - 1] == 0)
                    break;
                if (nums[k - 1] == nums[i]) {
                    ans.push_back(k);
                    nums[k - 1] = 0;
                    break;
                }
                swap(nums[i], nums[k - 1]);
                k = nums[i];
            }
            i++;
        }
        return ans;
    }
};