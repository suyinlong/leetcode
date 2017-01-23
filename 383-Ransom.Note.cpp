class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(256, 0);
        for (char c: ransomNote)
            m[c] ++;
        for (char c: magazine)
            m[c] --;
        for (int k: m)
            if (k > 0)
                return false;
        return true;
    }
};