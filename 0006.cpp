class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        // If n <= numRows, then it's a vertical line
        // If numRows == 1, then it's a horizontal line
        if (n <= numRows || numRows == 1) {
            return s;
        }

        // The zigzag loops in a pattern
        // In each loop, there are (numRows * 2 - 2) characters
        // Due to (numRow) characters on the vertical bit
        // And (numRow - 2) characters on the slanted bit
        int loop = numRows * 2 - 2;

        // Store the number of times the pattern repeats
        int iter = n / loop + (n % loop != 0);
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