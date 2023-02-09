class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Store the indexes of the numbers that we've encountered thus far
        unordered_map<int, int> umap;
        
        int n = nums.size();

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // If the complement (target - current number) had already been encountered
            if (umap.find(target - nums[i]) != umap.end()) {
                // Return the index of the complement and the current index
                return {umap[target - nums[i]], i};
            }
            // Else store the index of the current number
            umap[nums[i]] = i;
        }

        // Although the test cases are generated to always have a solution, 
        // we still need this just so that the code compiles
        return {};
    }
};