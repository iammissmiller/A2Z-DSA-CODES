#include <bits/stdc++.h>
using namespace std;

pair<int,int> findRMOptimal(vector<int>& arr, int n)
{
    long long S = (long long)n * (n + 1) / 2;
    long long S2 = (long long)n * (n + 1) * (2*n + 1) / 6;

    long long sum = 0, sqSum = 0;

    for(int x : arr)
    {
        sum += x;
        sqSum += (long long)x * x;
    }

    long long val1 = S - sum;                 // x - y
    long long val2 = S2 - sqSum;              // x² - y²

    val2 = val2 / val1;                      // x + y

    long long x = (val1 + val2) / 2;         // missing
    long long y = x - val1;                  // repeating

    return {(int)y, (int)x};
}
