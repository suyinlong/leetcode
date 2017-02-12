class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        multiset<int> set1, set2;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                if (set1.count(nums[i-k])) set1.erase(set1.lower_bound(nums[i-k]));
                else if (set2.count(nums[i-k])) set2.erase(set2.lower_bound(nums[i-k]));
            }
            if (set1.size() <= set2.size()) {
                if (set2.empty() || nums[i] <= *set2.begin()) set1.insert(nums[i]);
                else {
                    set1.insert(*set2.begin());
                    set2.erase(set2.begin());
                    set2.insert(nums[i]);
                }
            }
            else {
                if (nums[i] >= *set1.rbegin()) set2.insert(nums[i]);
                else {
                    set2.insert(*set1.rbegin());
                    set1.erase(--set1.end());
                    set1.insert(nums[i]);
                }
            }
            if (i >= k - 1) {
                if (k % 2) medians.push_back(*set1.rbegin());
                else medians.push_back(((double)*set1.rbegin() + (double)*set2.begin()) / 2);
            }
        }
        return medians;
    }
};