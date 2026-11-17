
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // Step 1: Precompute substring costs
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;

                // Try every valid divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;

                    // Check each group as a palindrome
                    for (int offset = 0; offset < d; offset++) {

                        int left = i + offset;
                        int right = i + len - d + offset;

                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // Step 2: Partition DP
        // dp[i][p] = minimum cost to divide s[i...n-1]
        // into exactly p semi-palindromes

        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INF));

        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {

            for (int p = 1; p <= k; p++) {

                // Need at least 2 characters per remaining part
                for (int j = i + 1;
                     j < n - 2 * (p - 1); j++) {

                    if (dp[j + 1][p - 1] == INF)
                        continue;

                    dp[i][p] = min(
                        dp[i][p],
                        cost[i][j] + dp[j + 1][p - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};
