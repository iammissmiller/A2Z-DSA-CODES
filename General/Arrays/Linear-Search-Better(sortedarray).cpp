#include <iostream>
using namespace std;

int linearSearchSorted(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
        else if (arr[i] > target)
            break;   // stop early
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5;
    int target = 5;

    int result = linearSearchSorted(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
