class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> map;

        for (string s: strs) {
            string c(s);
            sort(c.begin(), c.end());
            auto it = map.find(c);
            if (it != map.end())
                result[it->second].push_back(s);
            else {
                map[c] = result.size();
                result.push_back(vector<string>(1, s));
            }
        }

        return result;
    }
};