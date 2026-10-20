
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int r = 0, c = 0;

        while (true) {
            visited[r][c] = true;

            int nr = r, nc = c;

            if (grid[r][c] == 'L') nc--;
            else if (grid[r][c] == 'R') nc++;
            else if (grid[r][c] == 'U') nr--;
            else if (grid[r][c] == 'D') nr++;

            // Stop if the next move leaves the grid.
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                return {r, c};

            // Stop if the next cell was already visited.
            if (visited[nr][nc])
                return {r, c};

            r = nr;
            c = nc;
        }
    }
};
