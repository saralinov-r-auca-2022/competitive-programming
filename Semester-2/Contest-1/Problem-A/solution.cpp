#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

void solve() {
    int n; cin >> n;
    int counter = 0;
    int i = 0;

    if (n == 2 || n == 3) {
        cout << 0;
        return;
    }

    for (int j = 2; j <= sqrt(n); j++) {
        if (n % j == 0) {
            counter += 2;
        }
        i = j;
    }
    if ((int) (n / i) == sqrt(n)) {
        counter--;
    }
    cout << counter;
}

int main() {
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