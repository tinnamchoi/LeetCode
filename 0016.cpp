class Solution {
public:
    int threeSumClosest(vector<int>& nums, long target) {
        int n = nums.size();
        long ans = target < 0 ? INT_MAX : INT_MIN;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                long sum = nums[i] + nums[l] + nums[r];
                cout << "ans: " << ans << ", sum: " << sum << endl;
                ans = max(ans, target) - min(ans, target) > max(sum, target) - min(sum, target) ? sum : ans;
                if (sum > target) {
                    r--;
                    continue;
                }
                if (sum < target) {
                    l++;
                    continue;
                }
                return target;
            }
        }
        return ans;
    }
};