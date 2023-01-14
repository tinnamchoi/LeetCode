/* Word Pattern */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> cmap;
        unordered_map<string, int> smap;
        
        istringstream iss(s);
        int n = pattern.size();
        int i = 0;

        for (string word; iss >> word; i++) {
            if (cmap[pattern[i]] != smap[word]) {
                return false;
            }
            cmap[pattern[i]] = smap[word] = i + 1;
        }

        return true;
    }
};