class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> wordMap;
        for (string s: words) {
            int mask = 0;
            for (int i = 0; i < s.length(); i++)
                mask |= 1 << (s[i] - 'a');
            auto it = wordMap.find(mask);
            if (it == wordMap.end())
                wordMap[mask] = s.length();
            else if (it->second < s.length())
                wordMap[mask] = s.length();
        }
        int ans = 0;
        for (auto i = wordMap.begin(); i != wordMap.end(); i++)
            for (auto j = wordMap.begin(); j != wordMap.end(); j++)
                if ((i->first & j->first) == 0)
                    ans = max(ans, i->second * j->second);
        return ans;
    }
};