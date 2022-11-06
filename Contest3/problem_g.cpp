#include "bits/stdc++.h"

using namespace std;


void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    bool flag = true;
    int maxSegment = 0;
    vector<int> sushi(n);
    for (int &e: sushi) cin >> e;
    for (int i = 1; i <= n; i++) {
        if (sushi[i] == sushi[i - 1]) {
            flag ? a++ : b++;
        } else {
            flag ? a++ : b++;
            maxSegment = max(maxSegment, min(a, b));
            flag ? b = 0 : a = 0;
            flag = !flag;
        }
    }
    cout << maxSegment * 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
