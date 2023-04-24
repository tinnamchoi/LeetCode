class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if (n2 > n1) return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = n2 * 2;

        while (l <= r) {
            int m2 = l + (r - l) / 2;
            int m1 = n1 + n2 - m2;

            int l1 = m1 ? nums1[(m1 - 1) / 2] : INT_MIN;
            int l2 = m2 ? nums2[(m2 - 1) / 2] : INT_MIN;
            int r1 = m1 != n1 * 2 ? nums1[m1 / 2] : INT_MAX;
            int r2 = m2 != n2 * 2 ? nums2[m2 / 2] : INT_MAX;

            if (r2 < l1) l = m2 + 1;
            else if (l2 > r1) r = m2 - 1;
            else return (double)(max(l1, l2) + min(r1, r2)) / 2;
        }

        return -1;
    }
};