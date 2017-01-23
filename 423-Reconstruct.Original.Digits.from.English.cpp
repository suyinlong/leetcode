class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for (char c: s)
            count[c - 'a'] ++;
        vector<int> digits(10, 0);
        vector<string> word = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<int> orderI = {0, 2, 6, 8, 3, 4, 7, 5, 1, 9};
        vector<char> orderA = {'z', 'w', 'x', 'g', 't', 'r', 's', 'f', 'o', 'i'};

        for (int i = 0; i < 10; i++) {
            digits[orderI[i]] = count[orderA[i] - 'a'];
            for (char c: word[orderI[i]])
                count[c - 'a'] -= digits[orderI[i]];
        }

        string ans;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < digits[i]; j++)
                ans += to_string(i);
        }
        return ans;
    }
};