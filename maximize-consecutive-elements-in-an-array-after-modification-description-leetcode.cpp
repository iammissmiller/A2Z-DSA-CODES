class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int prev = nums[0];

        // a: best sequence ending at prev
        // b: best sequence ending at prev + 1
        int a = 1, b = 1;
        int ans = 1;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int diff = curr - prev;

            if (diff == 0) {
                b = max(a + 1, b);
            }
            else if (diff == 1) {
                int temp = max(a + 1, b);
                b = b + 1;
                a = temp;
            }
            else if (diff == 2) {
                a = b + 1;
                b = 1;
            }
            else {
                a = 1;
                b = 1;
            }

            ans = max(ans, max(a, b));
            prev = curr;
        }

        return ans;
    }
};
