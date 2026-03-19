#include <bits/stdc++.h>
using namespace std;

int maxSubarrayKadane(vector<int>& arr)
{
    int sum = 0;
    int maxSum = INT_MIN;

    for(int x : arr)
    {
        sum += x;

        maxSum = max(maxSum, sum);

        if(sum < 0)
            sum = 0;
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubarrayKadane(arr);
}
