#include <bits/stdc++.h>
using namespace std;

vector<int> removeduplicate(vector<int> a , int n)
{
    set<int> st;

    for(int i = 0; i < n ; i++)
    {
        st.insert(a[i]);
    }

    int index = 0;
    for(auto it: st)
    {
        a[index] = it;
        index++;
    }

    a.resize(index);   // keep only unique elements
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

    vector<int> result = removeduplicate(a, n);

    for(int x : result)
    {
        cout << x << " ";
    }

    return 0;
}
