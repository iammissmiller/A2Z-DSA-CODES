#include <bits/stdc++.h>
using namespace std;

vector<int> unionOptimal(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            if (result.empty() || result.back() != a[i])
                result.push_back(a[i]);
            i++;
        } else {
            if (result.empty() || result.back() != b[j])
                result.push_back(b[j]);
            j++;
        }
    }

    // remaining elements
    while (i < a.size()) {
        if (result.empty() || result.back() != a[i])
            result.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        if (result.empty() || result.back() != b[j])
            result.push_back(b[j]);
        j++;
    }

    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 5, 6};

    vector<int> result = unionOptimal(a, b);

    for (int x : result)
        cout << x << " ";

    return 0;
}
