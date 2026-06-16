class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;

        for(int num : nums) {
            mp[num] = true;
        }

        int longest = 0;

        for(auto &p : mp) {
            int num = p.first;

            if(mp.find(num - 1) == mp.end()) {
                int len = 1;
                int curr = num;

                while(mp.find(curr + 1) != mp.end()) {
                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }

        return longest;
    }
};
