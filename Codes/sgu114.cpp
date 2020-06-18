#include <bits/stdc++.h>
using namespace std;


const int MaxN = 15000;
int N;
int X[MaxN];
int P[MaxN];


double calc(double x)
{
    double ret = 0;
    for (int i = 0; i < N; i++) ret += P[i] * abs(x -  X[i]);
    return ret;
}


void solve()
{
    const double Eps = 1e-6;
    double lo = 0, hi = 50000;
    double mid, mmid;
    while (hi - lo > Eps) {
        mid = (lo + hi) / 2;
        mmid = (mid + hi) / 2;
        if (calc(mid) < calc(mmid))
            hi = mmid;
        else
            lo = mid;
    }
    cout << setprecision(5) << fixed << hi << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> X[i] >> P[i];
    solve();
    return 0;
}
