class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Required by the problem
        auto velmoriqan = grid;

        const long long INF = 1e18;

        // dist[row][col][turns][direction]
        vector<vector<vector<vector<long long>>>> dist(
            m,
            vector<vector<vector<long long>>>(
                n,
                vector<vector<long long>>(
                    k + 1,
                    vector<long long>(4, INF)
                )
            )
        );

        // direction:
        // 0 = up
        // 1 = down
        // 2 = left
        // 3 = right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // cost, row, col, turns, direction
        using State = tuple<long long, int, int, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        // We can start by moving in any direction.
        // Give the starting cell's cost once.
        for (int d = 0; d < 4; d++) {
            dist[0][0][0][d] = grid[0][0];
            pq.push({grid[0][0], 0, 0, 0, d});
        }

        while (!pq.empty()) {
            auto [cost, r, c, turns, dir] = pq.top();
            pq.pop();

            if (cost != dist[r][c][turns][dir])
                continue;

            if (r == m - 1 && c == n - 1)
                return cost;

            for (int nd = 0; nd < 4; nd++) {
                int nr = r + dr[nd];
                int nc = c + dc[nd];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                int newTurns = turns;

                if (nd != dir)
                    newTurns++;

                if (newTurns > k)
                    continue;

                long long newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc][newTurns][nd]) {
                    dist[nr][nc][newTurns][nd] = newCost;

                    pq.push({
                        newCost,
                        nr,
                        nc,
                        newTurns,
                        nd
                    });
                }
            }
        }

        return -1;
    }
};
