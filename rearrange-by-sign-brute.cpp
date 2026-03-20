#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangebysign(vector<int> &a) 
{   
    vector<int> pos, neg;

    for(int x : a)
    {
        if(x > 0) pos.push_back(x);
        else neg.push_back(x);
    }

    vector<int> result;
    int i = 0, j = 0;

    // Alternate elements
    while(i < pos.size() && j < neg.size())
    {
        result.push_back(pos[i++]);
        result.push_back(neg[j++]);
    }

    // Add remaining elements
    while(i < pos.size()) result.push_back(pos[i++]);
    while(j < neg.size()) result.push_back(neg[j++]);

    return result;
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

    vector<int> result = rearrangebysign(a);

    for(int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
