class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> st;
        long long ans = 0;

        for (int x : nums) {
            // Count elements strictly smaller than x
            ans += lower_bound(st.begin(), st.end(), x) - st.begin();

            // Remove elements that x blocks permanently
            while (!st.empty() && st.back() > x) {
                st.pop_back();
            }

            // Keep equal values
            st.push_back(x);
        }

        return ans;
    }
};
