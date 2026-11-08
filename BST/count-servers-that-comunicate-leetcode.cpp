class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        // First pass: count servers
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;

        // Second pass: count communicating servers
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 &&
                   (row[i] > 1 || col[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
