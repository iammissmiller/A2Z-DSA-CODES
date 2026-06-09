#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnesOptimal(vector<int>& arr) {
    int count = 0;
    int maxCount = 0;

    for (int x : arr) {
        if (x == 1) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }

    return maxCount;
}

int main() {
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    cout << maxConsecutiveOnesOptimal(arr);
}
