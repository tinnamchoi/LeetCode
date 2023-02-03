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
        int iter = ceil((float)n / (float)(loop));

        string ans;

        // Since we are reading this row-by-row
        // We'll iterate through the rows in the outer loop
        for (int i = 0; i < numRows; i++) {
            // We'll then iterate through each repeat of the pattern
            for (int j = 0; j < iter; j++) {
                // Adding the vertical bit
                // Using a temp variable to check whether the index is out of range
                int temp = j * loop + i;
                if (temp < n) {
                    ans.push_back((char)s[temp]);
                }
                // No slanted bit to add if we're on either the top or bottom row
                if (i == 0 || i == numRows - 1) {
                    continue;
                }
                // Adding the slanted bit
                temp = (j + 1) * loop - i;
                if (temp < n) {
                    ans.push_back((char)s[temp]);
                } 
            }
        }

        return ans;
    }
};