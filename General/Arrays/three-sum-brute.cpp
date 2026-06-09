#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> &arr) 
{   
    int n = arr.size();
    set<vector<int>> st;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            for(int k = j+1 ; k < n ; k++)
            {
                if(arr[i]+arr[j]+arr[k] == 0)
                {
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(),st.end());
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

    vector<vector<int>> ans = threesum(a);

    for(auto v : ans)
    {
        for(int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}
