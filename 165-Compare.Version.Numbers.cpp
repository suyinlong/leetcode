class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2)
            return 0;
        if (version1.length() == 0)
            return -1;
        if (version2.length() == 0)
            return 1;
        int t1 = version1.find("."), t2 = version2.find(".");
        if (t1 == -1)
            t1 = version1.length();
        if (t2 == -1)
            t2 = version2.length();
        int v1 = stoi(version1.substr(0, t1)), v2 = stoi(version2.substr(0, t2));
        if (v1 < v2)
            return -1;
        else if (v1 > v2)
            return 1;
        else {
            if (t1 == version1.length() && t2 == version2.length())
                return 0;
            else if (t1 == version1.length())
                return compareVersion("0", version2.substr(t2 + 1, version2.length() - t2 - 1));
            else if (t2 == version2.length())
                return compareVersion(version1.substr(t1 + 1, version1.length() - t1 - 1), "0");
            else
                return compareVersion(version1.substr(t1 + 1, version1.length() - t1 - 1), version2.substr(t2 + 1, version2.length() - t2 - 1));
        }

    }
};