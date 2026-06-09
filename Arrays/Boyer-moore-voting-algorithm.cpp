#include <bits/stdc++.h>
using namespace std;

vector<int> majorityelement(vector<int> &arr) 
{   
    int count1 = 0 ; int count2 = 0;
    int candidate1 = 0 ; int candidate2 = 0;

    //find candidate
    for(int x : arr)
    {
        if(x == candidate1)
        {
            count1++;
        }
        else if(count1 == 0)
        {
            count1 = 1;
        }
        else if(count2 == 0)
        {
            candidate2 = x;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    //verify 
    count1 = 0;
    count2 = 0;

    for(int x : arr)
    {
        if(x == candidate1) count1++;
        else if(x == canditate2) count2++;
    }

    vector<int> ans;
    int n = arr.size();

    if(count1 > n/3) ans.push_back(candidate1);
    if(count2 > n/3) ans.push_back(candidate2);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }

    vector<int> ans = majorityelement(a);

    for(int x : ans)
        cout << x << " ";
    return 0;
}
