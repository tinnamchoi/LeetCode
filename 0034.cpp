class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }

        vector<int> ans(2, -1);
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
                continue;
            }
            if ((nums[m] == target && m > 0 && nums[m - 1] == target) || nums[m] > target) {
                r = m;
                continue;
            }
            ans[0] = m;
            break;
        }

        if (ans[0] == -1) {
            return ans;
        }

        l = ans[0];
        r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target && m != n - 1 && nums[m + 1] == target) {
                l = m + 1;
                continue;
            }
            if (nums[m] > target) {
                r = m - 1;
                continue;
            }
            ans[1] = m;
            break;
        }

        return ans;
    }
};