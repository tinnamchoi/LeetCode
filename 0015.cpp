/* duplicate*/

class Solution {
public:
    string vint2string(vector<int> nums) {
        string ans = "";
        ans += to_string(nums[0]);
        ans += " ";
        ans += to_string(nums[1]);
        ans += " ";
        ans += to_string(nums[2]);
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<int> sums;
        int n = nums.size();
        unordered_set<string> s;
        vector<vector<int>> ans = {};
        for (int i = 0; i < n - 2; i++) {
            sums.insert(nums[i]);
            for (int j = i + 2; j < n; j++) {
                if (sums.find(0 - nums[i + 1] - nums[j]) != sums.end()) {
                    vector<int> temp = {nums[i + 1], nums[j], 0 - nums[i + 1] - nums[j]};
                    sort(temp.begin(), temp.end());
                    if (s.find(vint2string(temp)) != s.end()) {
                        continue;
                    }
                    ans.push_back(temp);
                    s.insert(vint2string(temp));
                }
            }
        }
        return ans;
    }
};