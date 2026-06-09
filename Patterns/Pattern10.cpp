// 22 pattern series pattern 10

#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n ; 
    cin >> n;

    for(int i = 0; i < n; i++) {
        int start = (i % 2 == 0) ? 1 : 0;
        for(int j = 0; j <= i; j++) {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }

    return 0;

}
