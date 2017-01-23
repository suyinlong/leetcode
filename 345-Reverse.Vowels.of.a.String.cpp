class Solution {
private:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        string ans(s);
        int i = 0, j = n - 1;

        while (i < j) {
            while (i < n && !isVowel(s[i])) i++;
            while (j >= 0 && !isVowel(s[j])) j--;
            if (i >= j) break;
            ans[i] = s[j];
            ans[j] = s[i];
            i++; j--;
        }

        return ans;
    }
};