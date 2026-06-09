#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == x)
            return mid;

        else if(arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1,3,5,7,9};
    int x = 7;

    cout << binarySearch(arr, x);
}
