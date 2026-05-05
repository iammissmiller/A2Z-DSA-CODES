#include <bits/stdc++.h>
using namespace std;

pair<int,int> findRMBrute(vector<int>& arr, int n)
{
    int repeating = -1, missing = -1;

    for(int i = 1; i <= n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[j] == i)
                count++;
        }

        if(count == 2) repeating = i;
        if(count == 0) missing = i;
    }

    return {repeating, missing};
}
