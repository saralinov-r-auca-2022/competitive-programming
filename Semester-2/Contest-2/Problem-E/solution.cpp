#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int money;
    cin >> money;
    sort(prices.begin(), prices.end());

    int l = 0;
    int r = n - 1;

    int price1, price2;
    while (l < r) {
        if (prices[l] + prices[r] == money) {
            price1 = prices[l];
            price2 = prices[r];
            l++;
            r--;
        } else if (prices[l] + prices[r] > money) {
            r--;
        } else {
            l++;
        }
    }

    cout << "Peter should buy books whose prices are " << price1 << " and " << price2 << ".\n";
    cout << "\n";
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
