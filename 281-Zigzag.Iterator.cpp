class ZigzagIterator {
private:
    vector<int> _v1, _v2;
    int m, a, b;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        _v1 = v1;
        _v2 = v2;
        a = 0;
        b = 0;
        if (v1.size() > 0)
            m = 0;
        else
            m = 1;
    }

    int next() {
        int r = (m == 0) ? _v1[a] : _v2[b];
        if (m == 0) {
            a++;
            if (b < _v2.size())
                m = 1;
        }
        else {
            b++;
            if (a < _v1.size())
                m = 0;
        }

        return r;
    }

    bool hasNext() {
        if (m == 0)
            return a < _v1.size();
        else
            return b < _v2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */