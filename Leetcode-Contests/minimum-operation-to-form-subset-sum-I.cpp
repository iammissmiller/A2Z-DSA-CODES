class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        function<int(int, int)> solve = [&](int i, int need) {
            if (need == 0)
                return 0;

            if (i == n)
                return INF;

            if (dp[i][need] != -1)
                return dp[i][need];

            // Option 1: don't use nums[i]
            int ans = solve(i + 1, need);

            // Option 2: multiply nums[i]
            long long x = nums[i];
            int operations = 0;

            while (x <= need) {
                ans = min(ans,
                          operations + solve(i + 1, need - x));

                x *= 2;
                operations++;
            }

            // IMPORTANT: reset operations
            x = nums[i];
            operations = 0;

            // Option 3: divide nums[i]
            while (x > 1) {
                x /= 2;
                operations++;

                if (x <= need) {
                    ans = min(ans,
                              operations + solve(i + 1, need - x));
                }
            }

            return dp[i][need] = ans;
        };

        int answer = solve(0, sum);

        return answer >= INF ? -1 : answer;
    }
};
