#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int MaxL = 21;
int S;
int f[MaxL][10];


void solve()
{
    f[0][0] = 1;
    for (int i = 1; i <= S; i++) {
        for (int d = 0; d <= 9; d++) {
            for (int dpre = 0; dpre <= d; dpre++)
                f[i][d] += f[i - 1][dpre];
        }
    }

    ll s = 1;    // number 0
    for (int i = 1; i <= S; i++) {
        for (int d1 = 1; d1 <= 9; d1++) {
            for (int d2 = 0; d2 < d1; d2++)
                s += f[i][d1] * f[S - i][d2];
        }
    }
    cout << s << endl;
}


int main()
{
    cin >> S;
    solve();
    return 0;
}
