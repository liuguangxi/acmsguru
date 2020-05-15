#include <bits/stdc++.h>
using namespace std;


using ll = long long;


ll powmod(ll a, ll b, ll m)
{
    ll c = 1;
    for (; b; b >>= 1, a = a * a % m) {
        if (b & 1) c = c * a % m;
    }
    return c;
}


// S(n, k) = 1/k! * sum(i = 0, k, (-1)^i * binomial(k, i) * (k - i)^n
void solve(int n, int k)
{
    int kfact = 1;
    for (int i = 2; i <= k; i++) kfact *= i;
    int m1 = kfact * 9;
    int m2 = kfact * 223;
    ll s1 = powmod(k, n, m1);
    ll s2 = powmod(k, n, m2);
    int sgn = 1;
    int bino = 1;
    for (int i = 1; i <= k; i++) {
        sgn = -sgn;
        bino = bino * (k + 1 - i) / i;
        s1 = (s1 + sgn * bino * powmod(k - i, n, m1) % m1 + m1) % m1;
        s2 = (s2 + sgn * bino * powmod(k - i, n, m2) % m2 + m2) % m2;
    }
    s1 /= kfact;
    s2 /= kfact;
    ll ans = (s1 * 892 + s2 * 1116) % 2007;
    cout << ans << endl;
}


int main()
{
    int N, K;
    cin >> N >> K;
    solve(N, K);
    return 0;
}
