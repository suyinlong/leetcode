class Solution {
public:
    int myAtoi(string str) {
        int i = 0, n = str.size(), sign = 1;
        while (i < n && str[i] == ' ') i++;
        if (i == n || (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))) return 0;
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
        }
        if (i == n) return 0;

        long long ulong = 0;
        while (i < n) {
            if (str[i] >= '0' && str[i] <= '9') {
                ulong *= 10;
                ulong += (str[i] - '0');
                if (sign == 1 && ulong >= INT_MAX) return INT_MAX;
                if (sign == -1 && ulong >= (long long)INT_MAX + 1) return INT_MIN;
            }
            if (str[i] == '+' || str[i] == '-')
                return 0;
            if (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
                break;
            i++;
        }
        if (sign == 1)
            return ulong;
        else
            return -ulong;
    }
};