#include <bits/stdc++.h>
using namespace std;

int largestsubarraysumzero(vector<int> &arr) 
{   
    int n = arr.size();

    int maxlen = 0;

    for(int i = 0 ; i < n ; i++)
    {
        int sum = 0;

        for(int j = i ; j<n ; j++)
        {
            sum = sum + arr[j];
            if(sum == 0)
            {
                maxlen = max(maxlen , j - i + 1);
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
