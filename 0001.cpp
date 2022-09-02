class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // loop through the array
      for (int i = 0; i < nums.size(); i++) {
        // loop through the array again
        for (int j = i + 1; j < nums.size(); j++) {
          // if the sum of the two numbers is equal to the target
          if (nums[i] + nums[j] == target) {
            // return the indices
            return {i, j};
          }
        }
      }
      return {};
    }
};