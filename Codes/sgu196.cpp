#include <bits/stdc++.h>
using namespace std;


using ll = long long;


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N, M;
	vector<int> deg;
	int u, v;
	ll ans = 0;

    cin >> N >> M;
	deg.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1; i <= N; i++) ans += (ll)deg[i] * (ll)deg[i];
    cout << ans << endl;
    return 0;
}
