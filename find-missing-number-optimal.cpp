#include <bits/stdc++.h>
using namespace std;

int findMissingOptimal(vector<int>& arr, int n) {
    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;

    for (int x : arr)
        arrSum += x;

    return totalSum - arrSum;
}

int main() {
    int n = 5;
    vector<int> arr = {1, 2, 4, 5};

    cout << findMissingOptimal(arr, n);
}
