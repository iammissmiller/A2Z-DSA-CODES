
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;
        const long long BASE = 911382323;

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        // Precompute powers and prefix hashes
        for (int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;

            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;
        }

        // Check whether a unique subarray of length len exists
        auto check = [&](int len) {
            unordered_map<unsigned long long, int> freq;
            freq.reserve(2 * n);

            for (int i = 0; i + len <= n; i++) {
                long long x1 =
                    (h1[i + len] - h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

                long long x2 =
                    (h2[i + len] - h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

                // Combine both hashes into one key
                unsigned long long key =
                    (static_cast<unsigned long long>(x1) << 32) |
                    static_cast<unsigned int>(x2);

                freq[key]++;
            }

            for (auto& [hash, count] : freq) {
                if (count == 1) {
                    return true;
                }
            }

            return false;
        };

        // Binary search for the smallest valid length
        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
