class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<int> velqoranim = nums;

        int n = nums.size();
        vector<int> power(15, 0);

        // Each group contains elements whose relative order
        // is already fixed by the higher bits.
        vector<vector<int>> groups;
        groups.push_back(velqoranim);

        // Process bits from 14 down to 0.
        for (int bit = 14; bit >= 0; bit--) {
            int index = 14 - bit;
            int onesCount = 0;

            for (int g = 0; g < groups.size(); g++) {
                vector<int>& group = groups[g];

                int cnt = 0;

                for (int x : group) {
                    if (x & (1 << bit))
                        cnt++;
                }

                onesCount += cnt;

                // Every element in this group has this bit = 1.
                // So the whole group can stay together.
                if (cnt == group.size()) {
                    continue;
                }

                // This is the first group where the prefix breaks.
                // Put all 1s before all 0s.
                vector<int> ones;
                vector<int> zeros;

                for (int x : group) {
                    if (x & (1 << bit))
                        ones.push_back(x);
                    else
                        zeros.push_back(x);
                }

                // Replace this group by [ones, zeros].
                groups[g] = ones;
                groups.insert(groups.begin() + g + 1, zeros);

                // All groups after this one cannot contribute
                // to the current prefix.
                break;
            }

            power[index] = onesCount;
        }

        return power;
    }
};
