class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0;

        for(int num : nums)
        {
            totalsum = num + totalsum;
        }

        int leftsum = 0;

        for(int i= 0 ; i < nums.size() ; i++)
        {
            int rightsum = totalsum - leftsum - nums[i];

            if(leftsum == rightsum)
            return i;

            leftsum = leftsum + nums[i];
        }

        return -1;
    }
};
