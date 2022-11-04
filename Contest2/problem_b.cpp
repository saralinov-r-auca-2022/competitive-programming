#include "bits/stdc++.h"

using namespace std;

vector<int> dividers() {
    int n = 5e5;
    vector<int> dividers(n + 1, 1);
    dividers[0] = 0;
    dividers[1] = 0;
    int i = 2, j;
    while (i <= n / 2) {
        j = 2 * i;
        while (j <= n) {
            dividers[j] = i + dividers[j];
            j += i;
        }
        i++;
    }
    return dividers;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> d = dividers();
    int t;
    cin >> t;
    int k;
    while (t--) {
        cin >> k;
        cout << d[k] << "\n";
    }
    return 0;
}