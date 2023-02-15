class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<int> sums;
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans = {};
        for (int i = 0; i < n - 2; i++) {
            sums.insert(nums[i]);
            for (int j = i + 2; j < n; j++) {
                if (sums.find(0 - nums[i + 1] - nums[j]) != sums.end()) {
                    vector<int> temp = {nums[i + 1], nums[j], 0 - nums[i + 1] - nums[j]};
                    sort(temp.begin(), temp.end());
                    if (s.find(temp) != s.end()) {
                        continue;
                    }
                    ans.push_back(temp);
                    s.insert(temp);
                }
            }
        }
        return ans;
    }
};