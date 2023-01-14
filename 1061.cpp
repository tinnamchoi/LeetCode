/* Lexicographically Smallest Equivalent String */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string minarray = "abcdefghijklmnopqrstuvwxyz";
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            int c1 = minarray[s1[i] - 'a'];
            int c2 = minarray[s2[i] - 'a'];
            if (c1 < c2) {
                for (int j = 0; j < 26; j++) {
                    if (minarray[j] == c2) {
                        minarray[j] = c1;
                    }
                }
            } else if (c2 < c1) {
                for (int j = 0; j < 26; j++) {
                    if (minarray[j] == c1) {
                        minarray[j] = c2;
                    }
                }
            }
        }
        int m = baseStr.size();
        for (int i = 0; i < m; i++) {
            baseStr[i] = minarray[baseStr[i] - 'a'];
        }
        return baseStr;
    }
};