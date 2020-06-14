#include <bits/stdc++.h>
using namespace std;


int main()
{
    int s, m, p;
    cin >> s >> m >> p;
    double ans;
    if (p == 0) {
        ans = (double)s / m;
    } else {
        double pp = p / 100.0;
        double t = pow(1 + pp, (double)m);
        ans = pp * t / (t - 1) * s;
    }
    cout << setprecision(8) << fixed << ans << endl;
    return 0;
}
