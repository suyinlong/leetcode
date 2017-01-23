class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<int>> diffMap;
        vector<vector<string>> ans;
        for (int i = 0; i < strings.size(); i++) {
            string s = strings[i];
            string diff = "";
            for (int j = 1; j < s.length(); j++) {
                int k = s[j] - s[j-1];
                if (k < 0)  k += 26;
                diff += to_string(k) + "#";
            }
            auto it = diffMap.find(diff);
            if (it == diffMap.end()) {
                vector<int> newIndex = {i};
                diffMap[diff] = newIndex;
            }
            else {
                it->second.push_back(i);
            }
        }
        for (auto it = diffMap.begin(); it != diffMap.end(); it++) {
            vector<string> group;
            for (auto iit = it->second.begin(); iit != it->second.end(); iit++ ) {
                group.push_back(strings[*iit]);
            }
            ans.push_back(group);
        }
        return ans;
    }
};