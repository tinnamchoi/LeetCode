class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n - 1;

        int ans = INT_MIN;

        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));

            int l_diff = height[l] - height[l + 1];
            int r_diff = height[r] - height[r - 1];

            if (l_diff > r_diff) {
                r--;
                continue;
            }
            if (r_diff > l_diff) {
                l++;
                continue;
            }

            l++;
            r--;
        }

        return ans;
    }
};