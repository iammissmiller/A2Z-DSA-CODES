#include <bits/stdc++.h>
using namespace std;

int longestsubarraybrute(vector<int> &a, int k) 
{
    int left = 0;
    int right = 0;
    int n = a.size();
    int maxlen = 0;
    int sum = 0;

    while(right < n)
    {
        sum = sum + a[right];

        while(sum > k)
        {
            sum = sum - a[left];
            left++;
        }

        if(sum == k)
        {
            maxlen = max(maxlen , right - left + 1);
        }

        right++;
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
