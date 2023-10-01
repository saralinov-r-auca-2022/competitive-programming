#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> arr(n);

    for (int &i: arr) {
        cin >> i;
    }

    sort(arr.begin(), arr.end());

    int l = 0;
    int r = n - 1;
    int mx = -1;

    while (l < r) {
        if (arr[l] + arr[r] <= m) {
            mx = max(mx, arr[l] + arr[r]);
            l++;
        } else {
            r--;
        }
    }

    cout << mx << "\n";
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
