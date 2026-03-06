#include <bits/stdc++.h>
using namespace std;

vector<int> dutchnationalflag(vector<int> &a) 
{   
    int count0 = 0 , count1 = 0 , count2 = 0 ;

    for(int x : a)
    {
        if(x == 0)
        {
            count0++;
        }
        else if(x == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    int i = 0;

    while(count0--)
    {
        a[i++] = 0;
    }
    while(count1--)
    {
        a[i++] = 1;
    }
    while(count2--)
    {
        a[i++] = 2;
    }

    return a;
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


    vector<int> result =  dutchnationalflag(a);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " " ;
    }

    return 0;
}
