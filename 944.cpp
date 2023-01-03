/* Delete Columns to Make Sorted */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // Count number of columns to be deleted
        int count = 0;

        // O(NM)
        // Iterate through each column
        for (int col = 0; col < strs[0].size(); col++) { // O(N)
            // Iterate through each row of the column
            for (int row = 1; row < strs.size(); row++) { // O(M)
                // If it is smaller than the previous row
                if (strs[row][col] < strs[row - 1][col]) {
                    // Increment counter and skip all remaining rows
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};