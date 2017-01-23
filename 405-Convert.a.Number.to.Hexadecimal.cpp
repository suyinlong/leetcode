class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "00000000";
        vector<char> table = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        for (int i = 0; i < 4; i++) {
            unsigned char *pointer = ((unsigned char *)&num) + i;
            unsigned char p = *pointer;
            hex[7 - 2 * i] = table[p % 16];
            hex[6 - 2 * i] = table[p / 16];
        }
        int j = 0;
        while (hex[j] == '0') j++;
        return hex.substr(j);
    }
};