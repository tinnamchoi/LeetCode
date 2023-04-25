class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int diff = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) { // O(n)
            int temp = gas[i] - cost[i];
            diff += temp;
            v[i] = temp;
        }
        if (diff < 0) { // O(1)
            return -1;
        }
        for (int i = 0; i < n; i++) { // O(n)
            if (v[i] < 0 || gas[i] == 0) {
                continue;
            }
            int tank = 0;
            // O(n) 
            for (int j = i; j < n; j++) {
                tank += v[j];
                if (tank < 0) {
                    goto fail;
                }
            }
            for (int j = 0; j < i; j++) {
                tank += v[j];
                if (tank < 0) {
                    goto fail;
                }
            }
            return i;
            fail:
            continue;
        }
        return -1;
    }
};