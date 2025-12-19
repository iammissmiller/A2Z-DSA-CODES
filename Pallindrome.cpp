#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ; 

    cin >> n;

    int copy = n;

    int rev = 0;  int last ;

    while(n>0)
    {
        last = n % 10;
        n = n/10;
        rev = (rev * 10) + last;
    }

    if(rev == copy)
    {
        cout << "The number " << copy << " is pallindrome";
    }
    else
    {
        cout << " The number " << copy <<" is not pallindrome";
    }

    return 0;

}
