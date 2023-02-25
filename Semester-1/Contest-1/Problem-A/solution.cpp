#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

void solve() {
    string s;
    cin >> s;
    auto half = (int) s.length() / 2;
    if (s.length() % 2 != 0) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < half; i++) {
        if (s[half + i] != s[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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