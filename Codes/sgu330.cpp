#include <bits/stdc++.h>
using namespace std;


using ll = long long;


ll lpf(ll n)
{
    if (n % 2 == 0) return 2;
    for (ll p = 3; p * p <= n; p += 2)
        if (n % p == 0) return p;
    return n;
}


void solve_even(ll a, ll b)
{
    ll n = a, d = 2;
    bool up = true;
    cout << n << endl;
    while (n < b) {
        if (up) {
            while (n % d == 0 && d < n) d *= 2;
            d /= 2;
            if (d <= b - n) {
                n += d;
                cout << n << endl;
            } else {
                up = false;
            }
        } else {
            while (d > b - n) d /= 2;
            n += d;
            cout << n << endl;
        }
    }
}


void solve(ll a, ll b)
{
    ll a2 = lpf(a);
    ll b2 = lpf(b);
    if (a2 == a || b2 == b) {
        cout << "Impossible" << endl;
        return;
    }
    a2 = (a % 2 == 1) ? a + a2 : a;
    b2 = (b % 2 == 1) ? b - b2 : b;
    if (a2 > b2) {
        cout << "Impossible" << endl;
        return;
    }
    if (a2 > a) cout << a << endl;
    solve_even(a2, b2);
    if (b2 < b) cout << b << endl;
}


int main()
{
    ll A, B;
    cin >> A >> B;
    solve(A, B);
    return 0;
}
