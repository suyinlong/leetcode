class Solution {
public:
    bool detectCapitalUse(string word) {
        bool up = false, low = false;
        bool firstUp = (word[0] >= 'A' && word[0] <= 'Z') ? true : false;
        for (int i = 1; i < word.size(); i++)
            if (word[i] >= 'A' && word[i] <= 'Z') up = true;
            else low = true;
        if (word.size() == 1 || (firstUp && up && !low) || (!firstUp && !up && low) || (firstUp && !up && low))
            return true;
        return false;
    }
};