#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> msg;
    for (int k = 0; k < n; k++) {
        cin >> a[k];
    }
    vector<int> indexes(n);
    for (int p; p < n; p++)
        indexes[p] = p;
    int k = n - 1;
    for (int t = 1; t < n && t != k;) {
        if (a[t] == 0) {
            a[t] = a[k];
            a[k] = 0;
            indexes[k] = indexes[t];
            indexes[t] = k;
            k--;
        } else {
            t++;
        }
    }
    for (int i = 0, j = 1; j < n;) {
        int x = indexes[i];
        int y = indexes[j];
        if (a[i] == 0) {
            cout << -1;
            return 0;
        }
        vector<int> v = {x + 1, y + 1};
        msg.emplace_back(v);
        a[i]--;
        j++;
        if (a[i] == 0) {
            i++;
        }
    }
    cout << msg.size() << endl;
    for (auto &b: msg) {
        cout << b[0] << " " << b[1] << endl;
    }

    return 0;
}
