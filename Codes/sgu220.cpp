#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int MaxN = 10;
int N, K;
int vo[MaxN];
int ve[MaxN];
ll f[MaxN][MaxN + 1];


ll calc(int v[], int n, int k)
{
    if (k == 0) return 1;
    memset(f, 0, sizeof(f));
    f[n - 1][1] = v[n - 1] - k + 1;
    for (int i = n - 2; i >= 0; i--)
        f[i][1] = v[i] - k + 1 + f[i + 1][1];
    for (int m = 2; m <= k; m++) {
        for (int i = n - m; i >= 0; i--)
            f[i][m] = (v[i] - k + m) * f[i + 1][m - 1] + f[i + 1][m];
    }
    return f[0][k];
}


void solve()
{
    for (int i = 0; i < N; i++) vo[i] = i / 2 * 2 + 1;
    for (int i = 0; i < N - 1; i++) ve[i] = i / 2 * 2 + 2;
    ll s = 0;
    for (int i = 0; i <= K; i++) {
        if (i <= N && K - i <= N - 1)
            s += calc(vo, N, i) * calc(ve, N - 1, K - i);
    }
    cout << s << endl;
}


int main()
{
    cin >> N >> K;
    solve();
    return 0;
}
