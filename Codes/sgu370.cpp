#include <bits/stdc++.h>
using namespace std;


using ll = long long;


ll solve(int n, int m)
{
    n--;
    m--;
    if (n == 0 && m == 0) return 0;
    if (n == 0 || m == 0) return 1;

    int nm = min(n, m);
    vector<bool> check(nm + 1);
    vector<int> prime;
    vector<int> mu(nm + 1);
    mu[1] = 1;
    for (int i = 2; i <= nm; i++) {
        if (!check[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (int p : prime) {
            if (i * p > nm) break;
            check[i * p] = true;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }

    ll s = 2;
    for (int k = 1; k <= nm; k++) {
        if (mu[k] != 0)
            s += ((ll)n / k) * ((ll)m / k) * mu[k];
    }
    return s;
}


int main()
{
    int N, M;
    cin >> N >> M;
    cout << solve(N, M) << endl;
    return 0;
}
