#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionBetter(vector<int>& a, vector<int>& b) {
    set<int> s(a.begin(), a.end());
    set<int> resultSet;

    for (int x : b) {
        if (s.count(x))
            resultSet.insert(x);
    }

    vector<int> result(resultSet.begin(), resultSet.end());
    return result;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4, 5};
    vector<int> b = {2, 2, 3, 5, 6};

    vector<int> result = intersectionBetter(a, b);

    for (int x : result)
        cout << x << " ";

    return 0;
}
