#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>& a , int n , int target) {
    
    int low = 0 , high = n-1 ;

    while(low <= high)
    {
        int mid = (high + low)/2;

        if(a[mid] == target )
        {
            return mid;
        }
        else if(a[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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

    int result = BinarySearch(a,n,target);

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
