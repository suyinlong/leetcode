class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        if (m == 0) return ((double)nums2[(n-1)/2] + (double)nums2[n/2]) / 2;

        int lo = 0, hi = m * 2;
        while (lo <= hi) {
            int mid1 = lo + (hi - lo) / 2;
            int mid2 = m + n - mid1;
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double R1 = (mid1 == m * 2) ? INT_MAX : nums1[mid1/2];
            double R2 = (mid2 == n * 2) ? INT_MAX : nums2[mid2/2];
            if (L1 > R2) hi = mid1 - 1;
            else if (L2 > R1) lo = mid1 + 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};