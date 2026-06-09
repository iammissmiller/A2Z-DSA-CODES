#include <bits/stdc++.h>
using namespace std;

vector<int> leadersOptimal(vector<int>& arr)
{
    int n = arr.size();
    vector<int> ans;

    int maxRight = INT_MIN;

    for(int i = n-1; i >= 0; i--)
    {
        if(arr[i] > maxRight)
        {
            ans.push_back(arr[i]);
            maxRight = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> arr = {10,22,12,3,0,6};

    vector<int> ans = leadersOptimal(arr);

    for(int x : ans)
        cout << x << " ";
}
