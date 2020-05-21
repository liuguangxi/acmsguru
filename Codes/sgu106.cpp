#include <bits/stdc++.h>
using namespace std;


using ll = long long;
int A, B, C, X1, X2, Y1, Y2;


int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}


ll solve()
{
    if (A == 0) {
        if (B == 0) {
            return (C == 0) ? (ll)(X2 - X1 + 1) * (ll)(Y2 - Y1 + 1) : 0;
        } else {
            int y = -C / B;
            return (C % B == 0 && y >= Y1 && y <= Y2) ? (X2 - X1 + 1) : 0;
        }
    } else if (B == 0) {
        int x = -C / A;
        return (C % A == 0 && x >= X1 && x <= X2) ? (Y2 - Y1 + 1) : 0;
    } else {
        int u, v;
        int g = exgcd(A, B, u, v);
        if (C % g != 0) return 0;
        ll mx = B / g;
        ll my = -A / g;
        ll x0 = (-C / g) * (ll)u;
        ll y0 = (-C / g) * (ll)v;
        ll t, kx1, kx2, ky1, ky2;
        if (mx > 0) {
            t = X1 - x0;
            kx1 = (t >= 0) ? (t + mx - 1) / mx : t / mx;
            t = X2 - x0;
            kx2 = (t >= 0) ? t / mx : (t - mx + 1) / mx;
        } else {
            t = X2 - x0;
            kx1 = (t >= 0) ? t / mx : (t + mx + 1) / mx;
            t = X1 - x0;
            kx2 = (t >= 0) ? (t - mx - 1) / mx : t / mx;
        }
        if (my > 0) {
            t = Y1 - y0;
            ky1 = (t >= 0) ? (t + my - 1) / my : t / my;
            t = Y2 - y0;
            ky2 = (t >= 0) ? t / my : (t - my + 1) / my;
        } else  {
            t = Y2 - y0;
            ky1 = (t >= 0) ? t / my : (t + my + 1) / my;
            t = Y1 - y0;
            ky2 = (t >= 0) ? (t - my - 1) / my : t / my;
        }
        if ((kx1 > kx2) || (ky1 > ky2)) return 0;
        if (kx1 <= ky1)
            return (kx2 < ky1) ? 0 : min(kx2, ky2) - ky1 + 1;
        else if (kx1 <= ky2)
            return min(kx2, ky2) - kx1 + 1;
        else
            return 0;
    }
}


int main()
{
    cin >> A >> B >> C >> X1 >> X2 >> Y1 >> Y2;
    cout << solve() << endl;
    return 0;
}
