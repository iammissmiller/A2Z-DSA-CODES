#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ; 

    cin >> n;

    int rev = 0 , last = 0;

    while(n>0)
    {
        last = n%10;
        n = n/10;
        rev = (rev * 10) + last;
    }

    cout << "Reversed number = "<< rev ;

    return 0;

}
