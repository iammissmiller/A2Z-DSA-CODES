class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        // P[i] = alternating sum of nums[0 ... i-1]
        vector<long long> P(n + 1, 0);

        for (int i = 0; i < n; i++) {
            P[i + 1] = P[i] + (i % 2 == 0 ? nums[i] : -nums[i]);
        }

        long long ans = P[n];

        const long long NEG = -(1LL << 60);

        // Maximum P[l] for each parity of l
        long long bestP[2] = {NEG, NEG};

        // Maximum P[l+1] for each parity of l
        long long bestP1[2] = {NEG, NEG};

        for (int r = 1; r < n; r++) {
            int l = r - 1;

            bestP[l % 2] = max(bestP[l % 2], P[l]);
            bestP1[l % 2] = max(bestP1[l % 2], P[l + 1]);

            long long gain;

            if (l % 2 == r % 2) {
                gain = 2LL * (bestP1[l % 2] - P[r + 1]);
            } else {
                gain = 2LL * (bestP[l % 2] - P[r + 1]);
            }

            ans = max(ans, P[n] + gain);
        }

        return ans;
    }
};
