class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long long low = lower, up = upper;

        for (int j: nums) {
            long long k = j;
            if (low == k)
                low++;
            else if (low < k) {
                long long i = k - 1;
                if (low == i)
                    ans.push_back(to_string(low));
                else
                    ans.push_back(to_string(low) + "->" + to_string(i));
                low = k + 1;
            }
        }
        if (low == up)
            ans.push_back(to_string(low));
        else if (low < up)
            ans.push_back(to_string(low) + "->" + to_string(up));
        return ans;
    }
};