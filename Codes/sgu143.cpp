#include <bits/stdc++.h>
using namespace std;


const int MaxN = 16000+10;
int N;
vector<int> G[MaxN];
int p[MaxN];
int num[MaxN];


void dfs(int u, int fa)
{
    num[u] = p[u];
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs(v, u);
        num[u] = max(num[u], num[u] + num[v]);
    }
}


void solve()
{
    dfs(1, 0);
    int ans = *max_element(num + 1, num + N + 1);
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> p[i];
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    solve();
    return 0;
}
