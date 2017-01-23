class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        vector<int> idx(10, 0);
        for (int i = 0; i < secret.size(); i++)
            if (secret[i] == guess[i])
                bull++;
            else
                idx[secret[i] - '0']++;
        for (int i = 0; i < guess.size(); i++)
            if (secret[i] != guess[i] && idx[guess[i] - '0'] > 0) {
                idx[guess[i] - '0'] --;
                cow++;
            }
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};