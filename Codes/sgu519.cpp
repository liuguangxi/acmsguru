#include <bits/stdc++.h>
using namespace std;


int N, M;
vector<string> S;


void solve()
{
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int h = S[i][j] - '0';
			if (h > 0) {
				ans += 4 * h + 2;
				if (i > 0) ans -= min(h, S[i - 1][j] - '0');
				if (i < N - 1) ans -= min(h, S[i + 1][j] - '0');
				if (j > 0) ans -= min(h, S[i][j - 1] - '0');
				if (j < M - 1) ans -= min(h, S[i][j + 1] - '0');
			}
		}
	}
	cout << ans << endl;
}


int main()
{
    cin >> N >> M;
	S.resize(N);
	for (int i = 0; i < N; i++) cin >> S[i];
	solve();
    return 0;
}
