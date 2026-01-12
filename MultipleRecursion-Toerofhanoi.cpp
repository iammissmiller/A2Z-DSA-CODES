#include <bits/stdc++.h>
using namespace std;

void toh(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk from " << A << " to " << C << endl;
        return;
    }

    toh(n - 1, A, C, B);   // first recursive call
    cout << "Move disk from " << A << " to " << C << endl;
    toh(n - 1, B, A, C);   // second recursive call
}

int main() {
    toh(3, 'A', 'B', 'C');
    return 0;
}
