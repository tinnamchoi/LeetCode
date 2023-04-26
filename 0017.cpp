class Solution {
private:
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string digits;
    vector<string> LC(int index) {
        if (index == -1) {
            return {""};
        }
        vector<string> temp = LC(index - 1);
        vector<string> ans;
        for (char c : letters[digits[index] - '0' - 2]) {
            for (string s : temp) {
                ans.push_back(s + c);
            }
        }
        return ans;
    }
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        return digits.size() == 0 ? vector<string> () : LC(digits.size() - 1);
    }
};