class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        if (s.size() == 0) return 0;
        vector<int> values(26, 0);
        values['I'-'A'] = 1; values['V'-'A'] = 5; values['X'-'A'] = 10; values['L'-'A'] = 50;
        values['C'-'A'] = 100; values['D'-'A'] = 500; values['M'-'A'] = 1000;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || values[s[i]-'A'] >= values[s[i+1]-'A'])
                result += values[s[i]-'A'];
            else
                result -= values[s[i]-'A'];
        }
        return result;
    }
};