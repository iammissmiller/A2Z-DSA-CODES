#include <bits/stdc++.h>
using namespace std;

int countSubarraysOptimal(vector<int>& arr, int k)
{
    unordered_map<int,int> mp;

    mp[0] = 1;

    int sum = 0;
    int count = 0;

    for(int x : arr)
    {
        sum += x;

        if(mp.find(sum - k) != mp.end())
        {
            count += mp[sum - k];
        }

        mp[sum]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {1,1,1};
    int k = 2;

    cout << countSubarraysOptimal(arr,k);
}
