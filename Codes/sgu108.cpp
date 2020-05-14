#include <bits/stdc++.h>
using namespace std;


int N, K;
vector<int> S;


int d(int n)
{
	int ret = n;
	while (n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}


void solve()
{
    vector<bool> sn(N + 1);
	vector<int> a(1);
	int num = 0;
	for (int i = 1; i <= N; i++) {
		if (!sn[i]) {
			num++;
			a.push_back(i);
		}
		int di = d(i);
		if (di <= N) sn[di] = true;
	}
	cout << num << endl;
	for (int k : S) cout << a[k] << " ";
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> K;
	S.resize(K);
	for (int i = 0; i < K; i++) cin >> S[i];
    solve();
    return 0;
}
