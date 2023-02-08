class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (umap[target - nums[i]] != 0) {
                return {umap[target - nums[i]] - 1, i};
            }
            umap[nums[i]] = i + 1;
        }
        return {};
    }
};