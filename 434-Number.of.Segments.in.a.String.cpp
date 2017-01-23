class Solution {
public:
    int countSegments(string s) {
        int seg = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i < n && s[i] != ' ') seg++;
            while (i < n && s[i] != ' ') i++;
        }
        return seg;
    }
};