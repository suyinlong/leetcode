class Solution {

public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0)
            return "";
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string ans;
        for (int k: nums)
            ans += to_string(k);
        return (ans[0] == '0') ? "0" : ans;
    }
};