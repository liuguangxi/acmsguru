#include <bits/stdc++.h>
using namespace std;


int chk(double x)
{
    if (abs(x) < 1e-9)
        return 0;
    else
        return x > 0 ? 1 : -1;
}


int main()
{
    double c, b, m;
    cin >> c >> b >> m;
    double x = (4 * m * m - b * b - c * c) / (2 * c);
    double y2 = b * b - x * x;
    if (chk(y2) >= 0) {
        if (chk(x) == 0) x = 0.0;
        if (chk(y2) == 0) y2 = 0.0;
        cout << setprecision(5) << fixed;
        cout << 0.0 << " " << 0.0 << endl;
        cout << c << " " << 0.0 << endl;
        cout << x << " " << sqrt(y2) << endl;
    } else {
        cout << "Mission impossible" << endl;
    }
    return 0;
}
