#include <iostream>
#include <vector>
using namespace std;

void moveZerosOptimal(vector<int>& arr) {
    int n = arr.size();
    int j = -1;

    // find first zero
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    // if no zero found
    if (j == -1) return;

    // swap with non-zero elements
    for (int i = j + 1; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    moveZerosOptimal(arr);

    for (int x : arr)
        cout << x << " ";
}
