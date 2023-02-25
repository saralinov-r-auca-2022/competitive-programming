#include "bits/stdc++.h"

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        cout << s / (int)(n - ceil(n / 2.0) + 1) << "\n";
    }
    return 0;
}
