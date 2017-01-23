class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
            return result;

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            auto it = map.find(t);
            if (it != map.end()) {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }
            map[nums[i]] = i;
        }
        return result;
    }
};