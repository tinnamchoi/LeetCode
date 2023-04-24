class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int num1;
        int num2;
        int j1 = 0;
        int j2 = 0;
        for (int i = 0; i <= (m + n) / 2; i++) {
            if (j1 < m && (j2 >= n || nums1[j1] <= nums2[j2])) {
                num1 = num2;
                num2 = nums1[j1];
                j1++;
            } else {
                num1 = num2;
                num2 = nums2[j2];
                j2++;
            }
        }
        return (m + n) % 2 ? num2 : (double)(num1 + num2) / 2;
    }
};