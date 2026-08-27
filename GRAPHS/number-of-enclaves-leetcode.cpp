class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Put all boundary land into the queue
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }

            if (grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                grid[i][n - 1] = 0;
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }

            if (grid[m - 1][j] == 1) {
                q.push({m - 1, j});
                grid[m - 1][j] = 0;
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        // Remove all land connected to the boundary
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }

        // Remaining 1s are enclaves
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};
