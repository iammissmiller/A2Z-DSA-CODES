#include <bits/stdc++.h>
using namespace std;

int searchInsertBrute(vector<int>& arr, int x)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] >= x)
            return i;
    }

    return arr.size();
}

int main()
{
    vector<int> arr = {1,3,5,6};
    int x = 2;

    cout << searchInsertBrute(arr, x);
}
