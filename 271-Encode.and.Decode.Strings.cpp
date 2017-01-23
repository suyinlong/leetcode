class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string es = "";
        for (string s:strs)
            es += to_string(s.length()) + "@" + s;
        return es;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int p = 0;
        vector<string> strs;
        while (p < s.length()) {
            int at_pos = s.find_first_of('@', p);
            int len = stoi(s.substr(p, at_pos - p));
            p = at_pos + 1;
            strs.push_back(s.substr(p, len));
            p += len;
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));