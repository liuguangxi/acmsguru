#include <bits/stdc++.h>
using namespace std;


const int MaxN = 16000+10;
int N;
vector<int> G[MaxN];
int sz[MaxN];
int num[MaxN];


void dfs(int u, int fa)
{
    sz[u] = 1;
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        num[u] = max(num[u], sz[v]);
    }
    num[u] = max(num[u], N - sz[u]);
}

void solve()
{
    dfs(1, 0);
    int minnum = *min_element(num + 1, num + N);
    int cnt = count(num + 1, num + N, minnum);
    cout << minnum << " " << cnt << endl;
    for (int i = 1; i <= N; i++)
        if (num[i] == minnum) cout << i << " ";
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    solve();
    return 0;
}
