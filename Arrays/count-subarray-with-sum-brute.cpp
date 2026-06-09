#include <bits/stdc++.h>
using namespace std;

int countSubarraysBrute(vector<int>& arr, int k)
{
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int j = i; j < n; j++)
        {
            sum += arr[j];

            if(sum == k)
                count++;
        }
    }

    return count;
}

int main()
{
    vector<int> arr = {1,1,1};
    int k = 2;

    cout << countSubarraysBrute(arr,k);
}
