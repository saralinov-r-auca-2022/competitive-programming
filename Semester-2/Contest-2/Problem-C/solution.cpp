#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

void solve() {
    int size; cin >> size;
    int sum; cin >> sum;

    vector<int> arr(size);

    for (int &i: arr) {
        cin >> i;
    }

    int l = 0;
    int r = size - 1;

    while (l < r) {
        if (arr[l] + arr[r] == sum) {
            cout << "YES" << "\n";
            return;
        }

        if (arr[l] + arr[r] < sum) {
            l++;
        } else {
            r--;
        }
    }

    cout << "NO" << "\n";
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
