class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string key = "";
        int seg = 0;
        int i = S.size() - 1;
        while (i >= 0 && S[i] == '-') i--;

        while (i >= 0) {
            if (isdigit(S[i]) || isupper(S[i]))
                key += S[i];
            else
                key += toupper(S[i]);
            seg++; i--;
            while (i >= 0 && S[i] == '-') i--;
            if (seg == K && i >= 0) {
                key += "-";
                seg = 0;
            }
        }
        reverse(key.begin(), key.end());
        return key;
    }
};