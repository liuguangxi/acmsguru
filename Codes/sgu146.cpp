#include <bits/stdc++.h>
using namespace std;


using ll = long long;


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    double L;
    int N;
    ll Ti, Vi, l, s = 0;
    cin >> L >> N;
    l = (ll)(L * 10000 + 0.5);
    for (int i = 0; i < N; i++) {
        cin >> Ti >> Vi;
        s += Ti * Vi;
    }
    s = s % l * 10000 % l;
    s = min(s, l - s);
    double ans = s/ 10000.0;
    cout << setprecision(4) << fixed << ans << endl;
    return 0;
}
