// 22 patterns using nesting for loop
// paatern 5

#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ;

    cin >> n;

    for (int i = 1 ; i <= n ; i++)
    {
        for(int j = i ; j <= n ; j++)
        {
            cout << j << " ";
        }

        cout << "\n";
    }

    return 0;

}
