#include <bits/stdc++.h>
using namespace std;


using ll = long long;
int N, M, K;
ll f[2][32768];


void solve()
{
    int NS = (1 << M);
    int cur = 0, pre;

    for (int s = 0; s < NS; s++)
        f[0][s] = (__builtin_popcount(s) >= K) ? 1 : 0;

    for (int i = M + 1; i <= N; i++) {
        pre = cur;
        cur ^= 1;
        memset(f[cur], 0, sizeof(f[cur]));
        for (int s = 0; s < NS; s++) {
            int snew = (s << 1) & (NS - 1);
            if (__builtin_popcount(snew) >= K) f[cur][snew] += f[pre][s];
            snew |= 1;
            if (__builtin_popcount(snew) >= K) f[cur][snew] += f[pre][s];
        }
    }

    ll ans = 0;
    for (int s = 0; s < NS; s++) ans += f[cur][s];
    cout << ans << endl;
}


int main()
{
    cin >> N >> M >> K;
    solve();
    return 0;
}
