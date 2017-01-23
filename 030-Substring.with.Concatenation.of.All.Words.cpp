class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), cnt = words.size();
        if (n <= 0 || cnt <= 0) return res;

        int len = words[0].size();
        unordered_map<string, int> dict;
        for (string w: words)
            dict[w]++;

        for (int i = 0; i < len; i++) {
            int start = i, count = 0;
            unordered_map<string, int> find;
            for (int j = i; j <= n - len; j += len) {
                string str = s.substr(j, len);
                if (dict.count(str)) {
                    find[str]++;
                    if (find[str] <= dict[str])
                        count++;
                    else {
                        while (find[str] > dict[str]) {
                            string str1 = s.substr(start, len);
                            find[str1]--;
                            if (find[str1] < dict[str1])
                                count--;
                            start += len;
                        }
                    }
                    if (count == cnt) {
                        res.push_back(start);
                        find[s.substr(start, len)]--;
                        count--;
                        start += len;
                    }
                }
                else {
                    find.clear();
                    count = 0;
                    start = j + len;
                }
            }
        }
        return res;
    }
};