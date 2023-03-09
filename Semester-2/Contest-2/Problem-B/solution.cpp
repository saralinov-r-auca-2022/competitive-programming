#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif


vector<int> make_sequence(int n) {
    vector<int> sequence(n);
    for (int &e: sequence) cin >> e;
    sort(sequence.begin(), sequence.end());
    return sequence;
}

void solve() {
    int k, l, m;
    cin >> k;
    vector<int> k_sequence = make_sequence(k);
    cin >> l;
    vector<int> l_sequence = make_sequence(l);
    cin >> m;
    vector<int> m_sequence = make_sequence(m);

    int i = 0, j = 0, q = 0;
    while (i + j + q < k + l + m) {
        if (i < k && (j >= l || k_sequence[i] <= l_sequence[j]) && (q >= m || k_sequence[i] <= m_sequence[q])) {
            cout << k_sequence[i] << " ";
            i++;
        } else if (j < l && (i >= k || l_sequence[j] <= k_sequence[i]) && (q >= m || l_sequence[j] <= m_sequence[q])) {
            cout << l_sequence[j] << " ";
            j++;
        } else if (q < m && (i >= k || m_sequence[q] <= k_sequence[i]) && (j >= l || m_sequence[q] <= l_sequence[j])) {
            cout << m_sequence[q] << " ";
            q++;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input_file = INPUT_FILE;
    if (input_file != "no") freopen(INPUT_FILE, "r", stdin);
    solve();
    return 0;
}