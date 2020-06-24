#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int MaxN = 10;
const int MaxCnt = 30000;
int N, K;
int cnt;
int sit[MaxCnt];
int mp[1 << (2 * MaxN)];
ll f[2][MaxCnt][MaxN * MaxN + 1];


void solve()
{
    if (K > 50) {
        cout << 0 << endl;
        return;
    }

    int NS = (1 << N);
    for (int s1 = 0; s1 < NS; s1++) {
        int msk = ((s1 >> 2) | (s1 << 2)) & (NS - 1);
        for (int s2 = 0; s2 < NS; s2++) {
            if ((s2 & msk) == 0) {
                int x = (s2 << N) | s1;
                sit[cnt] = x;
                mp[x] = cnt;
                cnt++;
            }
        }
    }

    f[0][0][0] = 1;
    int cur = 0, pre;
    for (int i = 1; i <= N; i++) {
        pre = cur;
        cur ^= 1;
        memset(f[cur], 0, sizeof(f[cur]));
        for (int j = 0; j < cnt; j++) {
            int x1 = sit[j] & (NS - 1);
            int x2 = (sit[j] >> N);
            int msk = ((x1 >> 1) | (x1 << 1) | (x2 >> 2) | (x2 << 2)) & (NS - 1);
            for (int s = 0; s < NS; s++) {
                if (s & msk) continue;
                int num = __builtin_popcount(s);
                int k = mp[(s << N) | x2];
                for (int p = num; p <= K; p++) f[cur][k][p] += f[pre][j][p - num];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < cnt; i++) ans += f[cur][i][K];
    cout << ans << endl;
}


int main()
{
    cin >> N >> K;
    solve();
    return 0;
}
