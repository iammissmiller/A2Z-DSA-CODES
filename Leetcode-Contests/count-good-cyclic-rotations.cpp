class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long left = 0;
        long long right = 0;

        // First rotation
        for (int i = 0; i < half; i++)
            left += nums[i];

        for (int i = half; i < n; i++)
            right += nums[i];

        int ans = 0;

        if (left > right)
            ans++;

        // Rotate one position at a time
        for (int i = 0; i < n - 1; i++) {
            left -= nums[i];
            right += nums[i];

            left += nums[(i + half) % n];
            right -= nums[(i + half) % n];

            if (left > right)
                ans++;
        }

        return ans;
    }
};
