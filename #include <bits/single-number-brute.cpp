#include <bits/stdc++.h>
using namespace std;

int singlenumberbrute(vector<int> &a) 
{
    int n = a.size() - 1 ;

    for(int i = 0 ; i < n ; i++)
    {
        int count = 0;

        for(int j = 0 ; j < n  ; j++ )
        {
            if( a[i] == a[j])
            {
                count++ ;
            }
        }

        if(count == 1)
            {
                return a[i];
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

    int result =  singlenumberbrute(a);

    cout << result;

    return 0;
}
