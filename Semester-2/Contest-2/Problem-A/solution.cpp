#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

void solve() {
    int n, m;
    cin >> n;

    vector<int> firstArr(n);
    vector<int> result;

    for (int i = 0; i < n; i++) {
        cin >> firstArr[i];
    }
    firstArr.push_back(INT_MAX);

    cin >> m;
    vector<int> secondArr(m);
    for (int i = 0; i < m; i++) {
        cin >> secondArr[i];
    }
    secondArr.push_back(INT_MAX);

    int i = 0;
    int j = 0;

    while (i < n || j < m) {
        if (firstArr[i] < secondArr[j]) {
            result.push_back(firstArr[i]);
            i++;
        } else {
            result.push_back(secondArr[j]);
            j++;
        }
    }

    for (i = 0; i < n+m; i++) {
        cout << result[i] << " ";
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