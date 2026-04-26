#include <bits/stdc++.h>
using namespace std;

int largestsubarraysumzero(vector<int> &arr) 
{   
    unordered_map<int,int> m;
    int sum = 0;
    int maxlen = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];

        if(sum == 0)
        {
            maxlen = max(maxlen, i + 1);
        }
        else
        {
            if(m.find(sum) != m.end())
            {
                maxlen = max(maxlen, i - m[sum]);
            }
            else
            {
                m[sum] = i;
            }
        }
    }

    return maxlen;
    
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

    int ans = largestsubarraysumzero(a);

    cout << ans << endl;

    return 0;
}
