#include <bits/stdc++.h>
using namespace std;

void mergeBrute(vector<int>& a, vector<int>& b)
{
    vector<int> temp;

    for(int x : a) temp.push_back(x);
    for(int x : b) temp.push_back(x);

    sort(temp.begin(), temp.end());

    int n = a.size();

    for(int i = 0; i < n; i++)
        a[i] = temp[i];

    for(int i = 0; i < b.size(); i++)
        b[i] = temp[n + i];
}
