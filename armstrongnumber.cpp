#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ; 

    cin >> n;

    int check = 0; int last = 0;

    while(n>0)
    {
        last = n%10;
        n = n/10;
        check = check + (last*last*last);
    }

    cout << check;

    return 0;

}
