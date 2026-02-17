#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionBrute(vector<int>& a, vector<int>& b) {
    vector<int> result;
    vector<bool> visited(b.size(), false);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j] && !visited[j]) {
                if (result.empty() || result.back() != a[i])
                    result.push_back(a[i]);
                visited[j] = true;
                break;
            }
        }
    }
    return result;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4, 5};
    vector<int> b = {2, 2, 3, 5, 6};

    vector<int> result = intersectionBrute(a, b);

    for (int x : result)
        cout << x << " ";

    return 0;
}
