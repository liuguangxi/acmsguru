#include <bits/stdc++.h>
using namespace std;


using ll = long long;
ll A, B, C;


inline ll f(ll x)
{
    return (A * x + x % B) % C;
}


int solve()
{
    const int T = 2000000;
    ll x1, x2;
    int k;

    x1 = x2 = 1;
    k = 0;
    do {
        x1 = f(x1);
        x2 = f(f(x2));
        k++;
    } while (k <= T && x1 != x2);
    if (x1 != x2) return -1;

    x1 = 1;
    k = 0;
    while (x1 != x2) {
        x1 = f(x1);
        x2 = f(x2);
        k++;
    }

    do {
        x2 = f(x2);
        k++;
    } while (x1 != x2);
    return (k <= T) ? k : -1;
}


int main()
{
    cin >> A >> B >> C;
    cout << solve() << endl;
    return 0;
}
