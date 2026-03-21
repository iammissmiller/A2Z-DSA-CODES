#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangebysign(vector<int> &arr) 
{   
    int n = arr.size();
    vector<int> result(n);

    int posIndex = 0;
    int negIndex = 1;

    for(int x : arr)
    {
        if(x > 0)
        {
            result[posIndex] = x;
            posIndex += 2;
        }
        else
        {
            result[negIndex] = x;
            negIndex += 2;
        }
    }

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
