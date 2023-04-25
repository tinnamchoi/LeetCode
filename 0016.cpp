class Solution {
public:
    int threeSumClosest(vector<int>& nums, long target) {
        int n = nums.size();
        long ans = target > 0 ? INT_MIN : INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    long sum = nums[i] + nums[j] + nums[k];
                    ans = max(sum, target) - min (sum, target) < max(ans, target) - min(ans, target) ? sum : ans;
                }
            }
        }
        return ans;
    }
};