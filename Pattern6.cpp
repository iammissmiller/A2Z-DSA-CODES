// 22 pattern series 
// pattern 6

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
            cout << char( 'a' + j) << " ";
        }

        cout << "\n";
    }

    return 0;

}
