#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ; 
    cin >> n;

     int total = 2*n - 1;
    for(int i = 1; i <= total; i++) {
        int stars = (i <= n) ? i : (2*n - i);
        for(int j = 0; j < stars; j++) cout << "* ";
        cout << endl;
    }

    return 0;

}
