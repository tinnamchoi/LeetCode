/* Word Pattern */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // unordered_map is more efficient than just map
        unordered_map<char, int> cmap;
        unordered_map<string, int> smap;
        
        istringstream iss(s);
        int n = pattern.size();
        int i = 0;

        for (string word; iss >> word; i++) { // O(m): Loop while iss is not empty, m is number of words in s
            if (i == n || cmap[pattern[i]] != smap[word]) { // If there are more words than the length of pattern OR the letter and word aren't mapped to the same integer
                return false;
            }
            cmap[pattern[i]] = smap[word] = i + 1; // Map to i + 1 to prevent mapping different words to the same integer
        }

        return i == n; // If the lengths are incremented the same, then i should've been incremented n times
    }
};