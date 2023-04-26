class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int curr = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (curr != nums[i]) {
                nums[slow] = nums[i];
                curr = nums[i];
                slow++;
            }
        }
        return slow;
    }
};