#include <bits/stdc++.h>
using namespace std;


const int MaxN = 10010;
const int MaxM = 1000;
int N, M;
int a[MaxN];
bool f[2][MaxM];
int idx[MaxM];
int dpre[MaxM];


void solve()
{
    f[0][1] = true;
    int cur = 0, pre;
    for (int i = 1; i <= N; i++) {
        if (a[i] == 1 || a[i] == M) continue;
        pre = cur;
        cur ^= 1;
        for (int j = 1; j < M; j++) f[cur][j] = f[pre][j];
        for (int j = 1; j < M; j++) {
            if (f[pre][j]) {
                int r = j * a[i] % M;
                if (r > 0 && !f[pre][r]) {
                    f[cur][r] = true;
                    idx[r] = i;
                    dpre[r] = j;
                }
            }
        }
    }

    int x = M - 1;
    while (!f[cur][x]) x--;
    cout << x << endl;
    if (x > 1) {
        vector<int> v;
        while (x > 1) {
            v.push_back(idx[x]);
            x = dpre[x];
        }
        reverse(v.begin(), v.end());
        for (int t : v) cout << t << " ";
        cout << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];
    solve();
    return 0;
}
