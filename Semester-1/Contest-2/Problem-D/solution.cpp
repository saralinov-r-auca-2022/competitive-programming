#include "bits/stdc++.h"

using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> isPrime(n - m + 1, 1);
    int i = 2, j;
    while (i <= sqrt(n)) {
        j = m + (i - (m % i == 0 ? i : m % i));
        if (isPrime[j - m] && i == j) {
            j += i;
        }
        while (j <= n) {
            isPrime[j - m] = 0;
            j += i;
        }
        i++;
    }
    for (int e = m; e <= n; e++) {
        if (isPrime[e - m] == 1 && e != 1) cout << e << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    bool isFirst = true;
    while (t--) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << "\n";
        }
        solve();
    }
    return 0;
}
