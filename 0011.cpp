class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, (j - i) * min(height[i], height[j]));
            }
        }

        return ans;
    }
};