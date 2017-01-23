class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.length() == 0 && str.length() == 0)
            return true;
        stringstream ss(str);
        string buf;
        vector<string> words;
        while (ss >> buf)
            words.push_back(buf);
        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> map;
        unordered_set<string> used;
        for (int i = 0; i < pattern.length(); i++) {
            auto it = map.find(pattern[i]);
            if (it == map.end()) {
                if (used.find(words[i]) != used.end())
                    return false;
                map[pattern[i]] = words[i];
                used.insert(words[i]);
            }
            else {
                if (it->second != words[i])
                    return false;
            }
        }

        return true;
    }
};