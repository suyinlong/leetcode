class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> abbrs;
        int n = word.size();

        for (int k = 0; k < (1 << n); k++) {
            string abbr = "";
            int culmulate = 0;

            for (int i = n - 1; i >= 0; i--) {
                int c = k & (1 << i);
                if (c == 0) {
                    if (culmulate > 0) {
                        abbr += to_string(culmulate);
                        culmulate = 0;
                    }
                    abbr += word[n-1-i];
                }
                else {
                    culmulate++;
                }
            }
            if (culmulate > 0)
                abbr += to_string(culmulate);
            abbrs.push_back(abbr);
        }
        return abbrs;
    }
};