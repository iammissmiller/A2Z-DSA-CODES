#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> freq;

    int arr[] = {1, 2, 2, 3, 1, 4, 2};

    for (int x : arr) {
        freq[x]++;   // hashing used here
    }

    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }
}
