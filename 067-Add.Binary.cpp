class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int maxLen = a.length() > b.length() ? a.length() : b.length();
        int carry = 0, idx_a = a.length() - 1, idx_b = b.length() - 1;
        for (int i = 0; i < maxLen; i++) {
            int ai = idx_a >= 0 ? a[idx_a] - '0' : 0;
            int bi = idx_b >= 0 ? b[idx_b] - '0' : 0;
            int vi = (ai + bi + carry) & 0x01;
            carry = (ai + bi + carry) >> 1;
            result += (vi + '0');
            idx_a --, idx_b --;
        }
        if (carry)
            result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};