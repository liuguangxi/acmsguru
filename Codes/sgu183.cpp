#include <bits/stdc++.h>
using namespace std;


const int MaxN = 10010;
const int MaxM = 100;
int N, M;
int C[MaxN];
int f[MaxN][MaxM];


void solve()
{
    memset(f, 0x3f, sizeof(f));
    f[0][1] = 0;
    for (int i = 1; i <= N + 1; i++) {
        int jmin = max(0, i - M + 1);
        for (int j = jmin; j < i; j++) {
            int d = i - j;
            int kmax = M - d;
            for (int k = 1; k <= kmax; k++)
                f[i][d] = min(f[i][d], f[j][k] + C[i]);
        }
    }

    int smin = 0x3f3f3f3f;
    for (int k = 1; k < M; k++) smin = min(smin, f[N + 1][k]);
    cout << smin << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> C[i];
    solve();
    return 0;
}
