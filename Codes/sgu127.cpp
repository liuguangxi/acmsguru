#include <bits/stdc++.h>
using namespace std;


int K, N;
vector<int> A;


void solve()
{
    int v[10] = {};
	for (int x : A) v[x / 1000]++;
	int ans = 2;
	for (int i = 1; i <= 9; i++) {
		if (v[i] > 0) ans += (v[i] - 1) / K + 1;
	}
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> K >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) cin >> A[i];
    solve();
    return 0;
}
