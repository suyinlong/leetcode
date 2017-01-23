class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN;
        for (int k: nums) {
            if (k > a) {
                c = b;
                b = a;
                a = k;
            }
            else if (k != a && k > b) {
                c = b;
                b = k;
            }
            else if (k != a && k != b && k > c) {
                c = k;
            }
        }
        if (c == LLONG_MIN)
            return (int)a;
        else
            return (int)c;
    }
};