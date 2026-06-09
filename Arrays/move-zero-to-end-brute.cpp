#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZerosBrute(vector<int> arr) {
    vector<int> temp;

    // store non-zero elements
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0)
            temp.push_back(arr[i]);
    }

    // count zeros
    int zeros = arr.size() - temp.size();

    // append zeros
    for (int i = 0; i < zeros; i++) {
        temp.push_back(0);
    }

    return temp;
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    vector<int> result = moveZerosBrute(arr);

    for (int x : result)
        cout << x << " ";
}
