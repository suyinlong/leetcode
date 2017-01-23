class ValidWordAbbr {
private:
    unordered_map<string, vector<string>> abbr;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string s: dictionary) {
            int n = s.length();
            string ab;
            if (n <= 2)
                ab = s;
            else
                ab = s.substr(0, 1) + to_string(n - 2) + s.substr(n - 1, 1);
            auto it = abbr.find(ab);
            if (it == abbr.end())
                abbr[ab] = vector<string>();
            bool dup = false;
            for (int i = 0; i < abbr[ab].size(); i++)
                if (abbr[ab][i] == s) {
                    dup = true;
                    break;
                }
            if (!dup)
                abbr[ab].push_back(s);
        }
    }

    bool isUnique(string word) {
        int n = word.length();
        string ab;
        if (n <= 2)
            ab = word;
        else
            ab = word.substr(0, 1) + to_string(n - 2) + word.substr(n - 1, 1);
        auto it = abbr.find(ab);
        if (it == abbr.end())
            return true;
        if (abbr[ab].size() == 1 && abbr[ab][0] == word)
            return true;
        return false;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");