class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.size() == 0)
            return ranges;

        int l = nums[0], r = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == r || nums[i] == r + 1)
                r = nums[i];
            else {
                if (l == r)
                    ranges.push_back(to_string(l));
                else
                    ranges.push_back(to_string(l) + "->" + to_string(r));
                l = nums[i];
                r = nums[i];
            }
        }
        if (l == r)
            ranges.push_back(to_string(l));
        else
            ranges.push_back(to_string(l) + "->" + to_string(r));
        return ranges;
    }
};