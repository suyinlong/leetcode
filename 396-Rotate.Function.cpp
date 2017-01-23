class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if (n == 0)
            return 0;

        int sum = 0, last = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            last += i * A[i];
        }
        int result = last;
        for (int i = 1; i < n; i++) {
            last = last + sum - n * A[n-i];
            result = max(last, result);
        }

        return result;
    }
};