#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOptimal(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            if (result.empty() || result.back() != a[i])
                result.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return result;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4, 5};
    vector<int> b = {2, 2, 3, 5, 6};

    vector<int> result = intersectionOptimal(a, b);

    for (int x : result)
        cout << x << " ";

    return 0;
}
