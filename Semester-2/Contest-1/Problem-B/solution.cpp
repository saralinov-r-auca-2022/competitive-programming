#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

void solve() {
    int a, b;
    cin >> a >> b;
    int counter = 0;
    int n = gcd(a, b);
    int i = 1;
    while ( i * i < n) {
        if (n % i == 0) {
            counter += 2;
        }
        i++;
    }
    if (i * i == n) {
        counter++;
    }
    cout << counter << "\n";

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