class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits);
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            ans[i] += carry;
            carry = ans[i] / 10;
            ans[i] %= 10;
        }
        if (carry > 0)
            ans.insert(ans.begin(), carry);
        return ans;
    }
};