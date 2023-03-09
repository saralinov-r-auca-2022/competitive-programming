#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

void solve() {
    int n; cin >> n;
    vector<int> sequence(n);

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int max_vertex = 0;
    int l = 0;
    int r = n - 1;

    while (l != r) {
        if (sequence[l] != max_vertex + 1) {
            l++;
        } else if (sequence[r] != max_vertex + 1) {
            r--;
        } else if (sequence[r] == sequence[l]) {
            max_vertex++;
        }
    }

    if (sequence[l] == max_vertex + 1) {
        max_vertex++;
    }

    cout << max_vertex << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input_file = INPUT_FILE;
    if (input_file != "no") freopen(INPUT_FILE, "r", stdin);

    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}