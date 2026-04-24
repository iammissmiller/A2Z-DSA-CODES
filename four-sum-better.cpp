#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> foursum(vector<int> &arr , int target) 
{   

    int n = arr.size();
    set<vector<int>> st;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            unordered_set<int> s;

            for(int k = j+1 ; k < n; k++)
            {
                int fourth = target - (arr[i] + arr[j] + arr[k]);

                if(s.find(fourth) != s.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                s.insert(arr[k]);
            }
        }
    }

    

    return vector<vector<int>>(st.begin(), st.end());
}

int main()
{
    int n;
    cin >> n;
    int target ;
    cin >> target;

    vector<int> a(n);

    for(int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> ans = foursum(a,target);

    for(auto v : ans)
    {
        for(int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}
