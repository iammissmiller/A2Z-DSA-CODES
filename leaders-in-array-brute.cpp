#include <bits/stdc++.h>
using namespace std;

vector<int> leadersBrute(vector<int>& arr)
{
    int n = arr.size();
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        bool leader = true;

        for(int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }

        if(leader)
            ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {10,22,12,3,0,6};

    vector<int> ans = leadersBrute(arr);

    for(int x : ans)
        cout << x << " ";
}
