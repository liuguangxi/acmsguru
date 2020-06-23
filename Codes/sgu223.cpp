#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int MaxN = 10;
const int MaxCnt = 150;
int N, K;
int cnt;
int sit[MaxCnt];
int sta[MaxCnt];
ll f[MaxN][MaxCnt][MaxN * MaxN + 1];


void dfs(int x, int num, int cur)
{
    if (cur >= N) {
        sit[cnt] = x;
        sta[cnt] = num;
        cnt++;
        return;
    }
    dfs(x, num, cur + 1);
    dfs(x | (1 << cur), num + 1, cur + 2);
}


void solve()
{
    dfs(0, 0, 0);
    for (int i = 0; i < cnt; i++) f[0][i][sta[i]] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < cnt; j++) {
            for (int k = 0; k < cnt; k++) {
                if (sit[j] & sit[k]) continue;
                if ((sit[j] << 1) & sit[k]) continue;
                if (sit[j] & (sit[k] << 1)) continue;
                for (int p = sta[j]; p <= K; p++) f[i][j][p] += f[i - 1][k][p - sta[j]];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < cnt; i++) ans += f[N - 1][i][K];
    cout << ans << endl;
}


int main()
{
    cin >> N >> K;
    solve();
    return 0;
}
