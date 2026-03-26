#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveBetter(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    int longest = 1;
    int count = 1;

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] == arr[i-1] + 1)
        {
            count++;
        }
        else if(arr[i] != arr[i-1])
        {
            count = 1;
        }

        longest = max(longest, count);
    }

    return longest;
}

int main()
{
    vector<int> arr = {100,4,200,1,3,2};

    cout << longestConsecutiveBetter(arr);
}
