#include <bits/stdc++.h>
using namespace std;

int majorityelement(vector<int> &a) 
{   
    unordered_map<int,int> mp;
    int n = a.size();

    for(int x : a )
    {
        mp[x]++;

        if(mp[x] > n/2)
        {
            return x;
        }
    }

    return -1;
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


    int result =  majorityelement(a);

    cout << result;

    return 0;
}
