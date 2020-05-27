#include <bits/stdc++.h>
using namespace std;


const int MaxL = 20;
int N, M;
int d[MaxL][MaxL];
int q[MaxL][MaxL];


void solve()
{
    for (int i = 0; i < M; i++) {
        vector<int> idx;
        for (int j = 0; j < N; j++) {
            vector<int> c(101);
            for (int k = 1; k <= d[j][0]; k++) c[d[j][k]] = 1;
            bool ok = true;
            for (int k = 1; k <= q[i][0]; k++) {
                int b = q[i][k];
                if ((b > 0 && c[b] == 0) || (b < 0 && c[-b] == 1)) {
                    ok = false;
                    break;
                }
            }
            if (ok) idx.push_back(j);
        }
        cout << idx.size() << endl;
        if (idx.size() > 0) {
            for (int x : idx) {
                for (int k = 0; k <= d[x][0]; k++) cout << d[x][k] << " ";
                cout << endl;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> d[i][0];
        for (int j = 1; j <= d[i][0]; j++) cin >> d[i][j];
    }
    for (int i = 0; i < M; i++) {
        cin >> q[i][0];
        for (int j = 1; j <= q[i][0]; j++) cin >> q[i][j];
    }
    solve();
    return 0;
}
