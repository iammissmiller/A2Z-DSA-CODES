#include <iostream>
#include <vector>
using namespace std;

void moveZerosBetter(vector<int>& arr) {
    int j = 0;

    // move non-zero elements forward
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            arr[j] = arr[i];
            j++;
        }
    }

    // fill remaining with zeros
    while (j < arr.size()) {
        arr[j] = 0;
        j++;
    }
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    moveZerosBetter(arr);

    for (int x : arr)
        cout << x << " ";
}
