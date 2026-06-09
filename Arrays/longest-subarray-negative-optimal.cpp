#include <bits/stdc++.h>
using namespace std;

int longestsubarrayoptimal(vector<int> &a, int k) 
{

    unordered_map<int,int> mp;

    int n = a.size();
    int maxlen = 0;
    int sum = 0;

    for(int i = 0 ; i < n ; i++)
    {
        sum = sum + a[i];

        if(sum == k)
        {
            maxlen = i+1;
        }

        if(mp.find(sum-k) != mp.end())
        {
            maxlen = max(maxlen , i-mp[sum-k]);
        }

        if(mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }


    }

    return maxlen;
   
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

    int result =  longestsubarrayoptimal(a,k);

    cout << result;

    return 0;
}
