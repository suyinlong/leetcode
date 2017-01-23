class Solution {
private:
    bool validHelper(vector<int> &data, int p) {
        if (p >= data.size())
            return false;
        if (((data[p] >> 6) & 3) == 2)
            return true;
        return false;
    }
public:
    bool validUtf8(vector<int>& data) {
        if (data.size() == 0)
            return true;
        int p = 0;
        while (p < data.size()) {
            if (((data[p] >> 7) & 1) == 0)
                p++;
            else if (((data[p] >> 5) & 7) == 6) {
                if (!validHelper(data, p+1))
                    return false;
                p += 2;
            }
            else if (((data[p] >> 4) & 15) == 14) {
                if (!validHelper(data, p+1) || !validHelper(data,p+2))
                    return false;
                p += 3;
            }
            else if (((data[p] >> 3) & 31) == 30) {
                if (!validHelper(data,p+1) || !validHelper(data,p+2) || !validHelper(data,p+3))
                    return false;
                p += 4;
            }
            else
                return false;
        }

        return true;

    }
};