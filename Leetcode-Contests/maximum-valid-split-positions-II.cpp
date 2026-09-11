class Solution {
public:

    vector<bool> mark(vector<int>& nums) {
        int n = nums.size();
        vector<bool> important(n, false);

        important[0] = true;

        int g = nums[0];

        for (int i = 1; i < n; i++) {
            int newG = gcd(g, nums[i]);

            if (newG != g)
                important[i] = true;

            g = newG;
        }

        return important;
    }

    int calculate(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefix[i] = gcd(prefix[i - 1], nums[i]);

        suffix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = gcd(suffix[i + 1], nums[i]);

        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] == suffix[i + 1])
                count++;
        }

        return count;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        // Positions where prefix GCD changes
        vector<bool> left = mark(nums);

        // Positions where suffix GCD changes
        vector<int> reversedNums = nums;
        reverse(reversedNums.begin(), reversedNums.end());

        vector<bool> right = mark(reversedNums);

        // Don't remove anything
        int ans = calculate(nums);

        // Try only important deletion positions
        for (int i = 0; i < n; i++) {

            if (!left[i] && !right[n - 1 - i])
                continue;

            vector<int> arr;
            arr.reserve(n - 1);

            for (int j = 0; j < n; j++) {
                if (j != i)
                    arr.push_back(nums[j]);
            }

            ans = max(ans, calculate(arr));
        }

        return ans;
    }
};
