class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (height[j] >= height[i]) {
                    ans = max(ans, (j - i) * height[i]);
                    break;
                }
                ans = max(ans, (j - i) * height[j]);
            }
        }

        return ans;
    }
};