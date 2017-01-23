class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> left(n, 0), right(n, 0);
        int lmax = height[0], rmax = height[n-1];
        left[0] = lmax;
        right[0] = rmax;

        for (int i = 1; i < n; i++) {
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[n-i-1]);
            left[i] = lmax;
            right[n-i-1] = rmax;
        }

        int total = 0;
        for (int i = 1; i < n - 1; i++) {
            int t = min(left[i], right[i]) - height[i];
            total += (t > 0) ? t : 0;
        }
        return total;
    }
};