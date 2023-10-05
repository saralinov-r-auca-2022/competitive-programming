#include <bits/stdc++.h>

using namespace std;

#ifndef INPUT_FILE
#define INPUT_FILE "no"
#endif

#define int long long

int MAX_N = 50000;
int MODULO = 1000000007;

vector<int> sieve(int n) {
    int i = 2, j;
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    while (i < (int) sqrt(n)) {
        if (sieve[i]) {
            j = i * i;
            while (j <= n) {
                sieve[j] = false;
                j += i;
            }
        }
        i += 1;
    }

    vector<int> sieve_arr;
    for (i = 0; i < sieve.size(); i++) {
        if (sieve[i]) {
            sieve_arr.push_back(i);
        }
    }
    return sieve_arr;
}

void solve(vector<map<int, int>> &divisors) {
    int n;
    cin >> n;
    int result = 1;

    vector<int> powers(MAX_N, 0);

    for (int i = 2; i <= n; i++) {
        for (auto e: divisors[i]) {
            powers[e.first] += e.second;
        }
    }

    for (int i = 2; i < powers.size(); i++) {
        result *= (powers[i] + 1) % MODULO;
        result %= MODULO;
    }

    cout << result << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input_file = INPUT_FILE;
    if (input_file != "no") freopen(INPUT_FILE, "r", stdin);

    vector<map<int, int>> divisors(MAX_N + 1);

    vector<int> sieve_arr = sieve((int) sqrt(MAX_N));


    for (int i = 2; i <= MAX_N; i++) {
        bool is_prime = true;
        for (int j : sieve_arr) {
            if (i % j == 0) {
                divisors[i] = divisors[i / j];
                divisors[i][j]++;
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            divisors[i][i] = 1;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve(divisors);
    }

    return 0;
}
