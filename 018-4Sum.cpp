class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> mp;

        for (int i = n - 1; i > 0; i--) {
            if (i < n - 1 && nums[i] == nums[i+1]) continue;
            for (int j = i - 1; j >= 0; j--) {
                if (j < i - 1 && nums[j] == nums[j+1]) continue;
                mp[nums[i]+nums[j]].push_back(make_pair(j, i));
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int p = target - nums[i] - nums[j];
                if (mp.find(p) != mp.end()) {
                    for (auto it = mp[p].begin(); it != mp[p].end(); it++) {
                        int a = (*it).first, b = (*it).second;
                        if (a > j) {
                            vector<int> qlet = {nums[i], nums[j], nums[a], nums[b]};
                            ans.push_back(qlet);
                        }
                    }
                }
            }
        }
        return ans;
    }
};