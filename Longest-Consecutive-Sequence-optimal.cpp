#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& arr)
{
    unordered_set<int> st(arr.begin(), arr.end());

    int longest = 0;

    for(int num : st)
    {
        if(st.find(num - 1) == st.end())
        {
            int current = num;
            int count = 1;

            while(st.find(current + 1) != st.end())
            {
                current++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {100,4,200,1,3,2};

    cout << longestConsecutive(arr);
}
