#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if (n < 5) {
        cout << "few";
    } else if (n < 10) {
        cout << "several";
    } else if (n < 20) {
        cout << "pack";
    } else if (n < 50) {
        cout << "lots";
    } else if (n < 100) {
        cout << "horde";
    } else if (n < 250) {
        cout << "throng";
    } else if (n < 500) {
        cout << "swarm";
    } else if (n < 1000) {
        cout << "zounds";
    } else {
        cout << "legion";
    }
    return 0;
}