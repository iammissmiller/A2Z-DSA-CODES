#include <bits/stdc++.h>
using namespace std;

vector<int> dutchnationalflag(vector<int> &a) 
{   
    sort(a.begin(),a.end());
    
    return a;
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


    vector<int> result =  dutchnationalflag(a);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " " ;
    }

    return 0;
}
