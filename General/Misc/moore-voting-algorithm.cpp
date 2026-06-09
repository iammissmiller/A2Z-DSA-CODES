#include <bits/stdc++.h>
using namespace std;

int majorityelement(vector<int> &a) 
{   
    int count = 0 ;
    int candidate = 0;

    for(int x : a)
    {
        if(count == 0)
        candidate = x;

        if (x == candidate)
        count++;

        else 
        count--;

    }

    return candidate;
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
