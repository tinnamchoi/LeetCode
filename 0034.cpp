class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target || (nums[m] == target && (m == 0 || nums[m - 1] == target))){
                r = m;
            } else {
                break;
            }
        }
        if (nums[l] != target) {
            return {-1, -1};
        }
        ans[0] = l;
        r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target && (m == n - 1 || nums[m + 1] > target)) {
                ans[1] = m;
                break;
            } else if (nums[m] == target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m;
            }
        }
        return ans;
    }
};