class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;
        if (k < 0) k *= -1;
        if (k == 0) {
            for (int i = 0; i < nums.size() - 1; i++)
                if (nums[i] == 0 && nums[i+1] == 0) return true;
            return false;
        }
        else {
            unordered_set<int> r;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                sum %= k;
                if (sum == 0 && i > 0) return true;
                if (r.find(sum) != r.end()) return true;
                r.insert(sum);
            }
            return false;
        }
    }
};