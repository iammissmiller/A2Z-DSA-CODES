// using reverse function in <algorithm> library


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // handles k > n

        // reverse entire array
        reverse(nums.begin(), nums.end());

        // reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
