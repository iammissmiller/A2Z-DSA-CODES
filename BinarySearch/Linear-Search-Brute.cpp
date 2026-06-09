#include <bits/stdc++.h>
using namespace std;

int LinearSearch(vector<int>& a , int n , int target) {
    
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == target){
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int target ;

    cin >> target;

    int result = LinearSearch(a,n,target);

    if(result != -1)
    {
        cout << "Element found at index " << result ;
    }
    else
    {
        cout << "Result not found";
    }

    return 0;
}
