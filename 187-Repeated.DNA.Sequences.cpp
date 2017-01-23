class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.length() <= 10)
            return ans;

        unordered_map<string, int> dnaMap;
        for (int i = 0; i <= s.length() - 10; i++) {
            string sub = s.substr(i, 10);
            dnaMap[sub]++;
            if (dnaMap[sub] == 2)
                ans.push_back(sub);
        }
        return ans;
    }
};