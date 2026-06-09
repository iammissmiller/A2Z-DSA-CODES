#include <bits/stdc++.h>
using namespace std;

int maxSubarrayBrute(vector<int>& arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0;

            for(int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubarrayBrute(arr);
}
