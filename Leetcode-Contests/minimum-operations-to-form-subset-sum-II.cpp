class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;

        // dp[s] = minimum operations needed to make sum s
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;

        for (int num : nums) {

            // Store all possible (value, operations) for this number
            vector<pair<int, int>> options;

            // First, keep dividing
            int x = num;
            int divOps = 0;

            while (x > 0) {
                // From this value, we can multiply
                int y = x;
                int mulOps = 0;

                while (y <= sum) {
                    options.push_back({y, divOps + mulOps});

                    if (y > sum / 2)
                        break;

                    y *= 2;
                    mulOps++;
                }

                x /= 2;
                divOps++;
            }

            // Use this number or skip it
            vector<int> newDp = dp;

            for (int current = 0; current <= sum; current++) {
                if (dp[current] == INF)
                    continue;

                for (auto [value, cost] : options) {
                    if (current + value <= sum) {
                        newDp[current + value] =
                            min(newDp[current + value],
                                dp[current] + cost);
                    }
                }
            }

            dp = newDp;
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};
