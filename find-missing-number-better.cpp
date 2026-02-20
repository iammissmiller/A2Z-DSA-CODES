#include <bits/stdc++.h>
using namespace std;

int findMissingBetter(vector<int>& arr, int n) {
    vector<int> freq(n + 1, 0);

    for (int x : arr) {
        freq[x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0)
            return i;
    }
    return -1;
}

int main() {
    int n = 5;
    vector<int> arr = {1, 2, 4, 5};

    cout << findMissingBetter(arr, n);
}
