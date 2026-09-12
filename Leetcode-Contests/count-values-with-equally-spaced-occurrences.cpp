class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> pos(101);

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;

        for (int x = 1; x <= 100; x++) {
            if (pos[x].size() == 3) {
                int a = pos[x][0];
                int b = pos[x][1];
                int c = pos[x][2];

                if (b - a == c - b)
                    ans++;
            }
        }

        return ans;
    }
};
