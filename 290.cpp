/* Word Pattern */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap;
        istringstream iss(s);
        string word;
        for (int i = 0; i < pattern.size(); i++) {
            iss >> word;
            if (umap.find(pattern[i]) != umap.end()) {
                if (umap[pattern[i]] != word) {
                    return false;
                }
                continue;
            }
            umap[pattern[i]] = word;
        }
        return true;
    }
};