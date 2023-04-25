class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        int temp = 0;
        for (int i = 1; i < points.size(); i++) {
            temp++;
            bool inc = false;
            for (int j = 1; j <= temp; j++) {
                if (points[i][0] > points[i - j][1]) {
                    inc = true;
                }
            }
            if (inc) {
                count++;
                temp = 0;
            }
        }
        return count;
    }
};