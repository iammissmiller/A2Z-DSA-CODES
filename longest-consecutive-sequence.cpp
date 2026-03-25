#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& arr, int num)
{
    for(int x : arr)
        if(x == num)
            return true;

    return false;
}

int longestConsecutiveBrute(vector<int>& arr)
{
    int n = arr.size();
    int longest = 1;

    for(int i = 0; i < n; i++)
    {
        int x = arr[i];
        int count = 1;

        while(linearSearch(arr, x + 1))
        {
            x = x + 1;
            count++;
        }

        longest = max(longest, count);
    }

    return longest;
}

int main()
{
    vector<int> arr = {100,4,200,1,3,2};

    cout << longestConsecutiveBrute(arr);
}
