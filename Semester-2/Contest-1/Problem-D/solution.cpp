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

int inverse(int a, int m) {
    return a <= 1 ? a : m - (int) (m / a) * inverse(m % a, m) % m;
}

int mod_divide(int a, int b, int m) {
    a = a % m;
    int inv = inverse(b, m);
    if (inv == -1) {
        return -1;
    } else {
        return (inv * a) % m;
    }
}

void solve(vector<int> &number_of_divisors) {
    int n;
    cin >> n;

    cout << number_of_divisors[n] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input_file = INPUT_FILE;
    if (input_file != "no") freopen(INPUT_FILE, "r", stdin);

    vector<map<int, int>> divisors(MAX_N + 1);
    vector<int> number_of_divisors(MAX_N + 1);
    vector<int> sieve_arr = sieve((int) sqrt(MAX_N));


    for (int i = 2; i <= MAX_N; i++) {
        bool is_prime = true;
        for (int j: sieve_arr) {
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

    map<int, int> powers;

    int result = 1;
    number_of_divisors[0] = 1;
    number_of_divisors[1] = 1;
    number_of_divisors[2] = 2;

    for (int i = 2; i <= MAX_N; i++) {
        for (auto e: divisors[i]) {
            if (powers[e.first]) {
                result = mod_divide(result, powers[e.first] + 1, MODULO);
                powers[e.first] += e.second;
                result *= (powers[e.first] + 1) % MODULO;
                result %= MODULO;
            } else {
                powers[e.first] = e.second;
                result *= (e.second + 1) % MODULO;
                result %= MODULO;
            }
        }
        number_of_divisors[i] = result;
    }

    int t;
    cin >> t;
    while (t--) {
        solve(number_of_divisors);
    }

    return 0;
}
