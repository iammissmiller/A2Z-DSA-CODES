#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;  // go left
        }
        else
        {
            low = mid + 1;   // go right
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1,2,4,4,5,6};
    int x = 4;

    cout << upperBound(arr, x);
}
