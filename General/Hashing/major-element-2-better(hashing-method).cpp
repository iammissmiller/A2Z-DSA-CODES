#include <bits/stdc++.h>
using namespace std;

vector<int> majorityelement(vector<int> &arr) 
{   
    int n = arr.size();
    unordered_map<int,int> mp;

    for(int x : arr)
    {
        mp[x]++;
    }

    vector<int> ans;

    for(auto it : mp)
    {
        if(it.second > n/3)
        {
            ans.push_back(it.first);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }

    vector<int> ans = majorityelement(a);

    for(int x : ans)
        cout << x << " ";
    return 0;
}
