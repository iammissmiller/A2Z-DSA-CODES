#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementBrute(vector<int>& arr)
{
    int n = arr.size();
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        // avoid duplicates
        bool already = false;
        for(int x : ans)
        {
            if(x == arr[i])
            {
                already = true;
                break;
            }
        }

        if(already) continue;

        for(int j = 0; j < n; j++)
        {
            if(arr[j] == arr[i])
                count++;
        }

        if(count > n/3)
            ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1,1,1,3,3,2,2,2};

    vector<int> ans = majorityElementBrute(arr);

    for(int x : ans)
        cout << x << " ";
}
