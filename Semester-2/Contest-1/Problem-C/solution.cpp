#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

void solve() {
    int n;
    cin >> n;
    int i = 1;

    vector<int> divisors;
    while (i * i < n) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
        i++;
    }

    if (i * i == n) {
        divisors.push_back(i);
    }

    sort(divisors.begin(), divisors.end());
    for (int j: divisors) {
        cout << j << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input_file = INPUT_FILE;
    if (input_file != "no") freopen(INPUT_FILE, "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
