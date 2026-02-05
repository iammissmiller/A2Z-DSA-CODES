#include <bits/stdc++.h>
using namespace std;

int Slargestelement(vector<int> a, int n )
{
    int slargest = -1;
    int largest = a[0];
    
    for(int i = 1; i < n ; i++)
    {
        if(a[i] > largest)
        {
            slargest = largest;
            largest = a[i];
        }
        else if(a[i] < largest && a[i] > slargest)
        {
            slargest = a[i];
        }
    }

    return slargest;
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

    cout << Slargestelement(a,n);

    return 0;
}
 
