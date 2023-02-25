#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string bits;
        int sum = 0;
        char previous = '2';
        cin >> bits;
        for (char b: bits) {
            if (sum == 2) {
                break;
            }
            if (b != previous && b == '0') {
                sum++;
            }
            previous = b;
        }
        cout << sum << "\n";
    }
    return 0;
}
