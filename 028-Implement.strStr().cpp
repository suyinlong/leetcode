class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        if (n == 0) return 0;
        for (int i = 0; i < m - n + 1; i++) {
            int j = 0;
            for (j = 0; j < n; j++)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == n) return i;
        }
        return -1;
    }
};