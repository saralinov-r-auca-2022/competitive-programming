#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> books;

    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        books.push_back(h);
    }

    vector<int> prefix_sums;
    prefix_sums.push_back(0);

    for (int i = 1; i <= n; ++i) {
        prefix_sums.push_back(prefix_sums[i - 1] + books[i - 1]);
    }

    int max = 0;
    int sum;

    for (int l = 0, r = 1; r <= n;) {
        sum = prefix_sums[r] - prefix_sums[l];
        if ((r - l) > max && sum <= m) {
            max = r - l;
        }
        if (sum >= m) {
            l++;
        } else if (sum < m) {
            r++;
        }
    }

    cout << max << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input_file = INPUT_FILE;
    if (input_file != "no") freopen(INPUT_FILE, "r", stdin);

    while (!cin.eof()) {
        solve();
    }
    return 0;
}
