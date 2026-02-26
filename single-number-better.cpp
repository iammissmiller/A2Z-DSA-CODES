#include <bits/stdc++.h>
using namespace std;

int singlenumberbetter(vector<int> &a) 
{
    unordered_map<int , int> freq;

    for(int x : a)
    {
        freq[x]++;
    }

    for( auto it : freq)
    {
        if(it.second == 1)
        {
            return it.first;
        }
    }

    return -1
   
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

    int result =  singlenumberbetter(a);

    cout << result;

    return 0;
}
