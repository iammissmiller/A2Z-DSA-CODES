#include <bits/stdc++.h>
using namespace std;

int Largestelement(vector<int> a, int n )
{
    int largest = a[0];
    
    for(int i = 0; i < n ; i++)
    {
        if(largest < a[i])
        {
            largest = a[i];
        }
    }

    return largest;
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

    cout << Largestelement(a,n);

    return 0;
}
