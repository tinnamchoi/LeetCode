class Solution {
public:
    vector<string> gp(int count, string cur, int remaining) {
        if (!count && !remaining) {
            return {cur};
        }
        vector<string> ans = {};
        if (remaining) {
            vector<string> temp = gp(count + 1, cur + '(', remaining - 1);
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        if (count) {
            vector<string> temp = gp(count - 1, cur + ')', remaining);
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }

    vector<string> generateParenthesis(int n) {
        return gp(0, "", n);
    }
};