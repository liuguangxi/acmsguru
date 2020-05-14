#include <bits/stdc++.h>
using namespace std;


int A[51][51];
int N, X;


void solve()
{
	int num = 0;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		if (i == X || A[X][i]) continue;
		for (int j = 1; j <= N; j++) {			
			if (A[X][j] && A[j][i]) {
				num++;
				v.push_back(i);
				break;
			}
		}
	}
	cout << num << endl;
	if (num > 0) {
		for (int x : v) cout << x << " ";
		cout << endl;
	}
}


int main()
{
    cin >> N >> X;
	int di, u;
	for (int i = 1; i <= N; i++) {
		cin >> di;
		for (int j = 0; j < di; j++) {
			cin >> u;
			A[i][u] = A[u][i] = true;
		}
	}
	solve();
    return 0;
}
