#include <bits/stdc++.h>
using namespace std;

int findMissingBrute(vector<int>& arr, int n) {
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found)
            return i;
    }
    return -1;
}

int main() {
    int n = 5;
    vector<int> arr = {1, 2, 4, 5};

    cout << findMissingBrute(arr, n);
}
