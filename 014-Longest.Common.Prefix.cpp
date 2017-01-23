class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        if (strs.empty())
            return ans;
        for (int i = 0; i < strs[0].size(); i++) {
            bool flag = true;
            for (int j = 0; j < strs.size(); j++)
                if (strs[0][i] != strs[j][i]) {
                    flag = false;
                    break;
                }
            if (flag)
                ans.push_back(strs[0][i]);
            else
                return ans;
        }
        return ans;
    }
};