#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int x)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1,3,5,7,9};
    int x = 7;

    cout << linearSearch(arr, x);
}
