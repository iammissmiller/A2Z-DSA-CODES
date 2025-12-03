//22 pattern printing series 
//pattern no. 3

#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ;

    cin >> n;

    for (int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            cout << i;
        }

        cout << "\n";
    }

    return 0;

}
