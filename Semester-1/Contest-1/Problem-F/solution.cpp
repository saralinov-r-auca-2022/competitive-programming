#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int n = 0;
    while (t--) {
        string s;
        cin >> s;
        if (s[1] == '-') {
            n--;
        } else {
            n++;
        }
    }
    cout << n << endl;
    return 0;
}
