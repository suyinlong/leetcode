class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size() == 0 || nums2.size() == 0)
            return ans;

        unordered_map<int, int> map;
        for (int i: nums1) {
            auto it = map.find(i);
            if (it != map.end())
                it->second++;
            else
                map[i] = 1;
        }
        for (int j: nums2) {
            auto it = map.find(j);
            if (it != map.end()) {
                ans.push_back(j);
                it->second--;
                if (it->second == 0)
                    map.erase(it);
            }
        }
        return ans;
    }
};