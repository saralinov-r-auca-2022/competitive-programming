#include "bits/stdc++.h"

using namespace std;

vector<int> prefixSums(vector<int> a) {

    vector<int> p(a.size());
    p[0] = a[0];
    for (int i = 1; i < a.size(); i++) {
        p[i] = p[i - 1] + a[i];
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> a(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }
    auto s = prefixSums(a);
    int q;
    cin >> q;
    int m, k;
    while (q--) {
        cin >> m;
        cin >> k;
        if (m == 0) {
            cout << s[k] << "\n";
        } else {
            cout << s[k] - s[m - 1] << "\n";
        }
    }
    return 0;
}