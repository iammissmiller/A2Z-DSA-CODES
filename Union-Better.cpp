#include <bits/stdc++.h>
using namespace std;

vector<int> unionBrute(vector<int> &a , vector<int> &b) 
{
    
    unordered_set<int> s;

    for(int x : a)
    s.insert(x);

    for(int x : b)
    s.insert(x);

    vector<int> result(s.begin() , s.end());
    sort(result.begin() , result.end());

    return result;
   
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> result = unionBrute(a,b);

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }


    return 0;
}
