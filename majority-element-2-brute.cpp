#include <bits/stdc++.h>
using namespace std;

vector<int> majorityelement(vector<int> &arr) 
{   
    int n = arr.size();
    vector<int> ans;

    for(int i = 0; i < n ; i++)
    {
        int count = 0;

        // ignore duplicates
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

        for(int j = 0; j < n ; j++)
        {
            if(arr[j] == arr[i])
            {
                count++;
            }
        }

        if(count > n/3)
        {
            ans.push_back(arr[i]);
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
