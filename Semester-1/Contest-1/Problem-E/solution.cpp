#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if (n <= 2 || n % 2 != 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}
