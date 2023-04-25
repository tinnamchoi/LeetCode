class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            char temp = 'a' - 1;
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] < temp) {
                    count++;
                    break;
                }
                temp = strs[j][i];
            }
        }
        return count;
    }
};