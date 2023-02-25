#include "bits/stdc++.h"

using namespace std;

vector<string> sieve() {
    int i = 2, j, n = 1e5;
    vector<string> sieve(n, "yes");
    sieve[0] = sieve[1] = "no";
    while (i < sqrt(n)) {
        if (sieve[i] != "no") {
            j = i * i;
            while (j <= n) {
                sieve[j] = "no";
                j += i;
            }
        }
        i += 1;
    }
    return sieve;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    vector<string> s = sieve();
    while (t--) {
        int k; cin >> k;
        cout << s[k] << "\n";
    }
    return 0;
}