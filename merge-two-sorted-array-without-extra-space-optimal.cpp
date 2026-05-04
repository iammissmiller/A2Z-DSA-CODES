#include <bits/stdc++.h>
using namespace std;

void mergeOptimal(vector<int>& a, vector<int>& b)
{
    int n = a.size();
    int m = b.size();

    int len = n + m;
    int gap = (len / 2) + (len % 2); // ceil

    while(gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while(right < len)
        {
            // case 1: both in a
            if(left < n && right < n)
            {
                if(a[left] > a[right])
                    swap(a[left], a[right]);
            }
            // case 2: left in a, right in b
            else if(left < n && right >= n)
            {
                if(a[left] > b[right - n])
                    swap(a[left], b[right - n]);
            }
            // case 3: both in b
            else
            {
                if(b[left - n] > b[right - n])
                    swap(b[left - n], b[right - n]);
            }

            left++;
            right++;
        }

        if(gap == 1) break;

        gap = (gap / 2) + (gap % 2);
    }
}
