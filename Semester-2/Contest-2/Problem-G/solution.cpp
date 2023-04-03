#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> hotels(n);
    for (auto &e: hotels) cin >> e;

    int l = 0;
    int r = n -1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input_file = INPUT_FILE;
    if (input_file != "no") freopen(INPUT_FILE, "r", stdin);

    solve();
    return 0;
}