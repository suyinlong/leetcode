class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size() == 0 || nums2.size() == 0)
            return ans;

        unordered_set<int> nset;
        for (int i: nums1)
            nset.insert(i);
        for (int j: nums2) {
            if (nset.count(j)) {
                ans.push_back(j);
                nset.erase(j);
            }
        }
        return ans;
    }
};