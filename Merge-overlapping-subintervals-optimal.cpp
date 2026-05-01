#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for(auto it : intervals)
    {
        if(ans.empty() || it[0] > ans.back()[1])
        {
            ans.push_back(it);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], it[1]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> intervals = {
        {1,3}, {2,6}, {8,10}, {15,18}
    };

    vector<vector<int>> ans = mergeIntervals(intervals);

    for(auto v : ans)
    {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
}
