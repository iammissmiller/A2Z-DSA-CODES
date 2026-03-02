#include <bits/stdc++.h>
using namespace std;

pair<int,int> twosum(vector<int> &a, int k) 
{   
    int n = a.size();

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(a[i]+a[j] == k)
            {
                return {i,j};
            }
        }
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
