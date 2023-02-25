#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n; cin >> n;
    string a; cin >> a;
    string b; cin >> b;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] == '1') {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}