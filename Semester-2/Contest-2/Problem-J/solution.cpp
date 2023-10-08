#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

void solve() {
    int p, m;
    cin >> p >> m;
    vector<int> planets;

    for (int i = 0; i < p; i++) {
        int a;
        cin >> a;
        planets.push_back(a);
    }

    int l = 0, r = 0, max = 0, sum = 0, min_sum = 0;
    for (; r < p; r++) {
        sum += planets[r];

        while (sum > m) {
            sum -= planets[l];
            l++;
        }

        if (r - l + 1 > max || r - l + 1 == max && min_sum > sum) {
            max = r - l + 1;
            min_sum = sum;
        }
    }

    cout << min_sum << " " << max << "\n";
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
