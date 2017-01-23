class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool neg = false;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            neg = true;
        long long ln = (numerator > 0) ? (long long)numerator : (long long)numerator * -1;
        long long ld = (denominator > 0) ? (long long)denominator : (long long)denominator * -1;

        long long d = ln / ld;
        string result = neg ? "-" + to_string(d) : to_string(d);
        long long n = ln % ld;

        if (n == 0)
            return result;
        result += ".";

        unordered_map<int, int> map;
        string f;
        n *= 10;
        while (n != 0) {
            auto it = map.find(n);
            if (it != map.end()) {
                f.insert(it->second, "(");
                f += ")";
                result += f;
                return result;
            }
            else {
                map[n] = f.length();
                f += ((n / ld) + '0');
                n %= ld;
                n *= 10;
            }
        }
        result += f;
        return result;
    }
};