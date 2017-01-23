class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(1, 0);
        if (num == 0)
            return result;
        result.push_back(1);
        if (num == 1)
            return result;
        int t = 1;
        for (int i = 2; i <= num; i++) {
            if (i == t * 2)
                t *= 2;
            result.push_back(result[i-t]+1);
        }
        return result;

    }
};