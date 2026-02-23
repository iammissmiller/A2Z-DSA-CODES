#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnesBrute(vector<int>& arr) {
    int n = arr.size();
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            int count = 0;
            for (int j = i; j < n && arr[j] == 1; j++) {
                count++;
            }
            maxCount = max(maxCount, count);
        }
    }

    return maxCount;
}

int main() {
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    cout << maxConsecutiveOnesBrute(arr);
}
