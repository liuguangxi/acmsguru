#include <bits/stdc++.h>
using namespace std;


using ld = long double;


int main()
{
    int p, q, r, a, b, c;
    cin >> p >> q >> r >> c >> b >> a;
    ld pp = (ld)p * p;
    ld qq = (ld)q * q;
    ld rr = (ld)r * r;
    ld qr = (qq + rr - (ld)a * a) / 2;
    ld rp = (rr + pp - (ld)b * b) / 2;
    ld pq = (pp + qq - (ld)c * c) / 2;
    ld det = -pp * qr * qr + 2 * pq * qr * rp - qq * rp * rp - pq * pq * rr + pp * qq * rr;
    ld ans = sqrt(det) / 6;
    cout << setprecision(4) << fixed << ans << endl;
    return 0;
}
