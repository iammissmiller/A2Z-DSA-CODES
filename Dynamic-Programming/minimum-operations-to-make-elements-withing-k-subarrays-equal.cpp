
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Step 1: Sliding window median using two multisets
        multiset<int> low, high;

        long long lowSum = 0, highSum = 0;

        auto rebalance = [&]() {
            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                lowSum -= v;

                high.insert(v);
                highSum += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                highSum -= v;

                low.insert(v);
                lowSum += v;
            }
        };

        auto add = [&](int v) {
            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                lowSum += v;
            } else {
                high.insert(v);
                highSum += v;
            }

            rebalance();
        };

        auto remove = [&](int v) {
            auto it = low.find(v);

            if (it != low.end()) {
                low.erase(it);
                lowSum -= v;
            } else {
                it = high.find(v);
                high.erase(it);
                highSum -= v;
            }

            rebalance();
        };

        // Step 2: Calculate cost of every window
        int m = n - x + 1;
        vector<long long> cost(m);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *low.rbegin();

                cost[i - x + 1] =
                    median * (long long)low.size() - lowSum
                    + highSum - median * (long long)high.size();
            }
        }

        // Step 3: DP with space optimization
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Option 1: Skip current position
                curr[i] = curr[i - 1];

                // Option 2: Select window ending at i - 1
                if (i >= x) {
                    int start = i - x;

                    curr[i] = min(
                        curr[i],
                        prev[start] + cost[start]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
