class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0)
            return true;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (!isalnum(s[i]))
                i++;
            while (!isalnum(s[j]))
                j--;
            if (i >= j)
                break;
            if (s[i] == s[j]) {
                i++, j--;
                continue;
            }
            if (isalpha(s[i]) && isalpha(s[j]) && tolower(s[i]) == tolower(s[j])) {
                i++, j--;
                continue;
            }
            return false;
        }
        return true;
    }
};