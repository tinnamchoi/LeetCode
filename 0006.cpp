class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1) {
            return s;
        }
        int loop = numRows * 2 - 2;
        int iter = ceil((float)n / (float)(loop));
        string ans;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < iter; j++) {
                if (j * loop + i < n) {
                    ans.append(1, s[j * loop + i]);
                } 
                if (i == 0 || i == numRows - 1) {
                    continue;
                }
                if ((j + 1) * loop - i < n) {
                    ans.append(1, s[(j + 1) * loop - i]);
                } 
            }
        }

        return ans;
    }
};