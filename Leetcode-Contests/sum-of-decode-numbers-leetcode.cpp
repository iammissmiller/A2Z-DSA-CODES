class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long MOD = 1000000007;
        long long total = 0;

        for (long long num : nums) {
            int width = num % 10;
            long long d = num / 10;

            // Count digits in d
            long long temp = d;
            int digits = 0;

            while (temp > 0) {
                digits++;
                temp /= 10;
            }

            // Find 10^(digits - width)
            long long p = 1;

            for (int i = 0; i < digits - width; i++) {
                p *= 10;
            }

            long long x = d / p;
            long long y = d % p;

            // Calculate x^y using binary exponentiation
            long long value = 1;

            while (y > 0) {
                if (y % 2 == 1)
                    value = (value * x) % MOD;

                x = (x * x) % MOD;
                y /= 2;
            }

            total = (total + value) % MOD;
        }

        return total;
    }
};
