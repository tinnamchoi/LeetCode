class Solution {
public:
	int find(vector<int>& uf, int i) {
		if (i == uf[i]) {
            return i;
        }
		uf[i] = find(uf, uf[i]);
		return uf[i];
	}

	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int m = edges.size();
		vector<int> uf(n);

		vector<vector<int>> x(n);
		for(int i = 0; i < n; i++){
			uf[i] = i;
			x[i] = {vals[i],1};
		}

        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b) {
	    	return max(vals[a[0]], vals[a[1]])<max(vals[b[0]], vals[b[1]]);
		});
		
        int count = 0;

        for (int i = 0; i < m; i++){
			int a = find(uf, edges[i][0]);
			int b = find(uf, edges[i][1]);
			if (x[a][0] != x[b][0]){
				if (x[a][0] > x[b][0]) {
                    uf[b] = a;
                } else {
                    uf[a]=b;
                }
			} else {
				uf[a] = b;
				count += x[a][1] * x[b][1];
				x[b][1] += x[a][1];
			}
		}
		return count + n;
	}
};