#include <bits/stdc++.h>
using namespace std;


int AH, AD, AM;


void solve()
{
    if (AH == AD && AD == AM) {
        double x = AH;
		cout << "YES" << endl;
        cout << setprecision(8) << fixed;
        cout << 0.0 << " " << x << endl;
        cout << -x << " " << 0.0 << endl;
        cout << x << " " << 0.0 << endl;
        return;
    }
    if (!(AH < AD && AD < AM)) {
        cout << "NO" << endl;
        return;
    }

    double t1 = sqrt(AM*AM - AH*AH + 0.0);
    double t2 = t1 * (2*AH*AH - AD*AD) / sqrt(AD*AD - AH*AH + 0.0) + AM*AM - 2*AH*AH;
    if (t2 <= 0) {
        cout << "NO" << endl;
        return;
    }
    double xb = t1 - sqrt(t2);
    double xc = t1 + sqrt(t2);
	cout << "YES" << endl;
    cout << setprecision(8) << fixed;
    cout << 0.0 << " " << (double)AH << endl;
    cout << xb << " " << 0.0 << endl;
    cout << xc << " " << 0.0 << endl;
}


int main()
{
    cin >> AH >> AD >> AM;
    solve();
    return 0;
}
