#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ; 
    cin >> n;

    for(int i = 0; i < n; i++) {

        for(int s = 0; s < n-i-1; s++) cout << " ";

        int limit = 2*i + 1;

        for(int j = 0; j < limit; j++) {
            int mid = limit/2;
            if(j <= mid) cout << char('a' + j);
            else cout << char('a' + limit - j - 1);
        }
        cout << endl;
    }

    return 0;

}
