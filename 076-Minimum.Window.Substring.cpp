class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c: t)
            m[c]++;
        int start = 0, end = 0, counter = t.length(), minStart = 0, minLength = INT_MAX, sSize = s.length();
        while (end < sSize) {
            if (m[s[end]] > 0)
                counter--;
            m[s[end]]--;
            end++;
            while (counter == 0) {
                if (end - start < minLength) {
                    minLength = end - start;
                    minStart = start;
                }
                m[s[start]]++;
                if (m[s[start]] > 0)
                    counter++;
                start++;
            }
        }
        if (minLength != INT_MAX)
            return s.substr(minStart, minLength);
        return "";
    }
};