#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

void solve() {
    int a, b;
    cin >> a >> b;
    vector<int> stations;

    for (int i = 0; i < a; i++) {
        int s;
        cin >> s;
        stations.push_back(s);
    }

    int max = 0, number_of_people = 0, sum = stations[0];

    for (int l = 0, r = 0; r < a;) {
        if (sum > b) {
            sum -= stations[l];
            if (l == r) {
                r++;
                sum += stations[r];
            }
            l++;
        } else {
            if (r - l + 1 > max) {
                max = r - l + 1;
                number_of_people = sum;
            } else if (r - l + 1 == max) {
                number_of_people = min(sum, number_of_people);
            }
            r++;
            sum += stations[r];
        }
    }

    cout << number_of_people << " " << max << "\n";
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
