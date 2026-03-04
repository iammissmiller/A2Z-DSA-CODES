#include <bits/stdc++.h>
using namespace std;

pair<int,int> twosum(vector<int> &a, int k) 
{   
    int n = a.size();
    unordered_map<int,int> mp;

    for(int i = 0 ; i< n ; i++)
    {
        int needed = k - a[i];

        if(mp.find(needed) != mp.end())
        {
            return {mp[needed] , i};
        }

        mp[a[i]] = i;
    }
    
    return {-1,-1};
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    cin >> k;

    pair<int,int> result =  twosum(a,k);

    cout << result.first << " " << result.second;

    return 0;
}
