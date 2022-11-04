#include "bits/stdc++.h"

using namespace std;


void solve() {
    int l;
    cin >> l;
    int max_value; cin >> max_value;
    int min_value = max_value;
    int n;
    for (int i = 1; i < l; i++) {
        cin >> n;
        if (n > max_value) {
            max_value = n;
        } else if (n < min_value) {
            min_value = n;
        }
    }
    cout << max_value - min_value << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
