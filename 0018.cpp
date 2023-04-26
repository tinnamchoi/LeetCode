class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;
        unordered_map<long, set<vector<int>>> umap;
        for (int b = 1; b < n - 2; b++) {
            for (int a = 0; a < b; a++) {
                vector<int> temp;
                temp.push_back(nums[a]);
                temp.push_back(nums[b]);
                sort(temp.begin(), temp.end());
                long lhs = nums[a] + nums[b];
                umap[lhs].insert(temp);
            }
            int c = b + 1;
            for (int d = b + 2; d < n; d++) {
                long rhs = (long)target - nums[c] - nums[d];
                for (auto v : umap[rhs]) {
                    v.push_back(nums[c]);
                    v.push_back(nums[d]);
                    sort(v.begin(), v.end());
                    ans.insert(v);
                }
            }
        }
        vector<vector<int>> ret;
        for (auto quad : ans) {
            ret.push_back(quad);
        }
        return ret;
    }
};