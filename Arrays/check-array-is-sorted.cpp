#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> a , int n)
{
    for(int i = 0; i < n ; i++)
    {
        if(a[i]<a[i+1] || a[i]== a[i+1])
        {
            
        }
        else return false;
    }

    return true;
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

    cout << isSorted(a,n);

    return 0;
}
 
