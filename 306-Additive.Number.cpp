class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if (n < 3)
            return false;
        long long num1 = 0, num2 = 0, num3 = 0;

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - i);
                string add = s1 + s2;

                if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0'))
                    continue;
                num1 = stoll(s1);
                num2 = stoll(s2);
                num3 = num1 + num2;
                string s3 = to_string(num3);

                if (num.find(s3, add.size()) != add.size())
                    continue;
                add += s3;

                while (add.size() < n) {
                    num1 = num2;
                    num2 = num3;
                    num3 = num1 + num2;
                    s3 = to_string(num3);
                    if (num.find(s3, add.size()) != add.size())
                        break;
                    add += s3;
                }

                if (add == num)
                    return true;

            }
        }
        return false;
    }
};