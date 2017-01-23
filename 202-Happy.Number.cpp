class Solution {
public:
    bool isHappy(int n) {
        if (n == 1)
            return true;
        set<int> s;
        s.insert(n);
        while (n != 1) {
            int t = 0;
            while (n) {
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
            if (s.count(n))
                return false;
            s.insert(n);
        }
        return true;
    }
};