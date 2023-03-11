class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> uset;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < 0 - nums[i]) {
                    l++;
                    continue;
                }
                if (sum > 0 - nums[i]) {
                    r--;
                    continue;
                }
                uset.insert({nums[i], nums[l], nums[r]});
                l++;
            }
        }

        vector<vector<int>> ans;
        for (vector<int> v : uset) {
            ans.push_back(v);
        }

        return ans;
    }
};