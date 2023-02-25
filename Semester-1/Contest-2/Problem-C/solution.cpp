#include <bits/stdc++.h>

using namespace std;

vector<bool> isPrime;
vector<int> prefixSums;

void sieve() {
    int n = 1e8;
    isPrime = vector<bool>(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    prefixSums = vector<int>(1e8 + 1);
    for (int i = 1; i <= 1e8; i++) {
        prefixSums[i] = prefixSums[i - 1] + isPrime[i];
    }

    int n;
    while (cin >> n, n != 0) {
        double error = fabs(prefixSums[n] - n / log(n)) / prefixSums[n] * 100;
        cout << fixed << setprecision(1) << error << "\n";
    }
    return 0;
}
