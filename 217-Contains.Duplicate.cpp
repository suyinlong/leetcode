class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        unordered_set<int> dup;
        for (int c: nums) {
            if (dup.count(c))
                return true;
            dup.insert(c);
        }
        return false;
    }
};