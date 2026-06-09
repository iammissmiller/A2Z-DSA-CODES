#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ; 

    cin >> n;

    for(int i = 2; i<n ; i++)
    {
        if(n%i == 0)
        {
            cout << n << " is not prime";
            exit(0);
        }
        else
        {
            cout << n << " is prime";
            exit(0);
        }
    }

    return 0;

}
