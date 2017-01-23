class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int k = nums[i];
            while (k != i + 1) {
                if (nums[k-1] == k)
                    break;
                swap(nums[i], nums[k-1]);
                k = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                ans.push_back(i+1);
        return ans;
    }
};