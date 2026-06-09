#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);

    cout << s.top();   // 20
    s.pop();
}
