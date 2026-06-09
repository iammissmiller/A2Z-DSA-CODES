#include <bits/stdc++.h>
using namespace std;

int longestsubarraybrute(vector<int> &a, int k) 
{
    int n = a.size();
    int maxlen = 0;

    for(int i = 0; i < n ; i++)
    {
        int sum = 0;

        for(int j = i ; j<n ; j++)
        {
            sum = sum + a[j];

            if(sum==k)
            {
                maxlen = max(maxlen , j-i+1);
            }

            if(sum>k)
            {
                break;
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

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    cin >> k;

    int result =  longestsubarraybrute(a,k);

    cout << result;

    return 0;
}
