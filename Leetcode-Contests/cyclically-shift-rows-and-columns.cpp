class Solution {
public:
    vector<vector<int>> cyclicShift(
        int n,
        vector<vector<int>>& grid,
        vector<int>& rowShift,
        vector<int>& colShift
    ) {
        // Shift each row to the left
        for (int i = 0; i < n; i++) {
            vector<int> temp(n);

            for (int j = 0; j < n; j++) {
                temp[j] = grid[i][(j + rowShift[i]) % n];
            }

            grid[i] = temp;
        }

        // Shift each column upward
        for (int j = 0; j < n; j++) {
            vector<int> temp(n);

            for (int i = 0; i < n; i++) {
                temp[i] = grid[(i + colShift[j]) % n][j];
            }

            for (int i = 0; i < n; i++) {
                grid[i][j] = temp[i];
            }
        }

        return grid;
    }
};
