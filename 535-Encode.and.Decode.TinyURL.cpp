class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (m.find(longUrl) != m.end())
            return m[longUrl];
        string tinyurl = "";
        id++;
        int count = id;
        while (count > 0) {
            tinyurl = dict[count%62] + tinyurl;
            count /= 62;
        }
        m[longUrl] = prefix + tinyurl;
        idm[id] = longUrl;
        return prefix + tinyurl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int count = 0;
        shortUrl = shortUrl.substr(19);
        for (int i = 0; i < shortUrl.size(); i++)
            count = count * 62 + (int)(dict.find(shortUrl[i]));
        if (idm.find(count) != idm.end())
            return idm[count];
        return "";
    }
private:
    int id = 0;
    string prefix = "http://tinyurl.com/";
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> m;
    unordered_map<int, string> idm;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));